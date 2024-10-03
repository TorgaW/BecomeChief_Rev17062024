import matplotlib.pyplot as plt
from collections import Counter
from tkinter import Tk, filedialog

# Функция для выбора файла
def select_file():
    root = Tk()
    root.withdraw()  # Скрыть главное окно
    file_path = filedialog.askopenfilename(title="Выберите файл с числами", filetypes=[("Text Files", "*.txt")])
    root.destroy()  # Уничтожить главное окно после выбора файла
    return file_path

# Запрос файла у пользователя
file_path = select_file()
if not file_path:
    print("Файл не выбран.")
else:
    # Чтение чисел из файла
    with open(file_path, 'r') as file:
        numbers = [int(line.strip()) for line in file]

    # Подсчет количества вхождений каждого числа
    number_counts = Counter(numbers)

    # Подготовка данных для графика
    numbers = list(number_counts.keys())
    counts = list(number_counts.values())

    # Построение гистограммы
    plt.figure(figsize=(10, 6))
    plt.bar(numbers, counts, color='skyblue')
    plt.xlabel('Numbers')
    plt.ylabel('Count')
    plt.title('Distribution')
    plt.grid(axis='y')

    # Показ графика
    plt.show()