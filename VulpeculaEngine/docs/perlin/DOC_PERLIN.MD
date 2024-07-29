# Perlin noise

## Public structs:

### SPerlinFBMParams
```
typedef struct SPerlinFBMParams {

    float gain;
    //synonym for 'lacunarity' word
    float lake;
    float amplitude;
    float frequency;

} SPerlinFBMParams;
```
#### Init function
```init_perlin_fbm_params(SPerlinFBMParams* src)```

Will init **src** struct with default values. **src** must not be ```NULL```.

---
### SPerlinDomainWarpingParams
```
typedef struct SPerlinDomainWarpingParams {

    float vx0, vy0, vx1, vy1, vx2, vy2, vx3, vy3;
    float p;

} SPerlinDomainWarpingParams;
```
- **vx0, vy0, vx1, vy1, vx2, vy2, vx3, vy3** - values for 4 rotation vectors to create 'fluid-like' motion.
- **p** is final multiplier.

#### Init function
```void init_perlin_domain_warping_params(SPerlinDomainWarpingParams* src);```

Will init **src** struct with default values. **src** must not be ```NULL```.



## Public functions:

```float calc_perlin_2d(float x, float y, SNoise* noise)```

Returns calculated ```float``` value from the given _x_ and _y_ coordinates in range [-1, 1]. 
- Param **noise** must not be ```NULL```

---

```float calc_perlin_fbm_2d(float x, float y, uint8_t octaves, SPerlinFBMParams* params, SNoise* noise)```

Like ```calc_perlin_2d(...)``` returns ```float``` value in range [-1, 1] based on _x_ and _y_ coordinates. However, this function works with _Fractal Brownian Motion_ filter. 
- **octaves** should be <= 9
- **params** and **noise** must not be ```NULL```

---

```float calc_perlin_fbm_ridged_2d(float x, float y, uint8_t octaves, SPerlinFBMParams* params, SNoise* noise)```

Same as ```calc_perlin_fbm_2d(...)``` but applies _Ridged_ filter at the end of the calculations and returns value in range [0, 1]. 
- **octaves** should be <= 9
- **params** and **noise** must not be ```NULL```

---

```float calc_perlin_dwfbm_2d(float x, float y, uint8_t octaves, SPerlinFBMParams* params, SPerlinDomainWarpingParams* dwParams, SNoise* noise)```

Same as ```calc_perlin_fbm_2d(...)``` but applies _Domain Warping_ filter at the end. Returns in range [-1, 1].

- **octaves** should be <= 9
- **params**, **dwParams** and **noise** must not be ```NULL```

---

```float calc_perlin_dwfbm_ridged_2d(float x, float y, uint8_t octaves, SPerlinFBMParams* params, SPerlinDomainWarpingParams* dwParams, SNoise* noise);```

Same as ```float calc_perlin_dwfbm_2d(...)``` but applies _Ridged_ filter at the end. Returns in range [0, 1].

- **octaves** should be <= 9
- **params**, **dwParams** and **noise** must not be ```NULL```

---

## Examples
```c
//create SNoise struct
SNoise noise = {.noiseType = NOISE_PERLIN};
alloc_noise(&noise, 512, 512);

//create SMathRandomState for PRNG
SMathRandomState rState = {.seed = 0xFFFF};

//prepare SNoise struct for perlin noise generation
gen_perlin_random_values(&noise, &rState);

//create FBM params
SPerlinFBMParams fbmParams;
init_perlin_fbm_params(&fbmParams);
fbmParams.lake = 1.5f;

//create DW params
SPerlinDomainWarpingParams dwParams;
init_perlin_domain_warping_params(&dwParams);
dwParams.p = 1.2f;

//loop through square
int w = 512, h = 512;
for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
        //calculate and store perlin noise value at i, j with 7 octaves
        //and modified FBM and DW params
    noise.data[i * h + j] = calc_perlin_dwfbm_2d((j) * 0.05f + 0.05f, (i) * 0.05f + 0.05f, 7, &fbmParams, &dwParams, &noise) * 0.5f + 0.5f;
    //and don't forget to clamp result in range [0, 1] with multiplying by 0.5 and adding 0.5
    //other solution is using fm_clamp_f() function from fmath.h but result will be with extremely low exposure (too black).
    }
}
```