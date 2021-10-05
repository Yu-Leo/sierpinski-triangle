# Sierpinski triangle

## Навигация

* [Описание проекта](#chapter-0)
* [Как начать](#chapter-1)
* [Интерфейс](#chapter-2)
* [Код](#chapter-3)
* [Лицензия](#chapter-4)

<a id="chapter-0"></a>

## :page_facing_up: Описание проекта

Посторение [треугольника Серпинского](https://ru.wikipedia.org/wiki/%D0%A2%D1%80%D0%B5%D1%83%D0%B3%D0%BE%D0%BB%D1%8C%D0%BD%D0%B8%D0%BA_%D0%A1%D0%B5%D1%80%D0%BF%D0%B8%D0%BD%D1%81%D0%BA%D0%BE%D0%B3%D0%BE) методом хаоса


<a id="chapter-1"></a>

## :hammer: Как начать

1. Установить [Visual Studio 2019](https://visualstudio.microsoft.com/ru/downloads/)
2. Скачать [SFML](https://www.sfml-dev.org/download.php)
3. Скачать данный репозиторий
   * Вариант 1
      1. Установить [Git](https://git-scm.com/download/win)
      2. Клонировать репозиторий
      ```bash
      git clone https://github.com/Yu-Leo/snake-game.git
      cd snake-game
      ```
   * Вариант 2 - [Скачать ZIP](https://github.com/Yu-Leo/sierpinski-triangle/archive/refs/heads/main.zip)
4. Подключить SFML к проекту ([как это сделать](https://www.sfml-dev.org/tutorials/2.5/start-vc.php))
5. Скомпилировать и запустить `./sierpinski-triangle/main.cpp`

<a id="chapter-2"></a>

## :camera: Интерфейс

![main_menu](./docs/img/main-menu.jpg)

<a id="chapter-3"></a>

## :computer: Код

[Техническая документация](./docs/technical-documentation.pdf)

### :file_folder: Папки

**sierpinski-triangle** - исходный код проекта.


### :wrench: Настройки


1. Генерация точек в случайных (`true`) или псевдо-случайных (`false`) местах
```cpp
// main.cpp

#define RANDOM_GENERATING false
```

При установке `false` стартовое значение для псевдо-случайной генерации задаётся в строчке
```cpp
// main.cpp

    srand(0); // Set seed for pseudorandom number generator
```

<a id="chapter-4"></a>

## :open_hands: Лицензия

Используете мой код - ставьте звёздочку ⭐️ на репозиторий

Автор: [Yu-Leo](https://github.com/Yu-Leo)

GNU General Public License v3.0

Полный текст в [LICENSE](LICENSE)
