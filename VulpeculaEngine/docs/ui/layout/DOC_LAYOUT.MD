# UI Layout

UI Layout is a array-like container with copies of widgets. This container provides instant change of UI pages.
#### For example 
Let's imagine we have several "windows" with UI:
- Main menu
- Options
- Single player level selection
- Multiplayer lobby interface

All of these "menus" or "windows" can be made with lots of widgets. It can be a little hard to switch between them as you must search though entire array of widgets inside ```engineApp``` variable. However layouts comes to stage. Layouts stored in inline memory, that prevents time consuming search for necessary root element.

But don't think about layout as "container" in GUI. There is existing type for widget: ```WIDGET_TYPE_CONTAINER```. Use layout for different windows or pages (like in HTML).

---

### Public structs
```cpp
typedef struct SUILayout {
	SArray* widgets;
	int zOrder;
} SUILayout;
```
---

### Public functions
```cpp
SUILayout* ui_create_layout(int zOrder);
```
Creates new ```SUILayout``` struct.