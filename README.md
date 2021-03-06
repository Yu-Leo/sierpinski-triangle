<h1 align="center"> Sierpinski triangle </h1>

<p align="center">
  <a href="#" target="_blank"> <img alt="license" src="https://img.shields.io/github/license/Yu-Leo/sierpinski-triangle?style=for-the-badge&labelColor=090909"></a>
  <a href="#" target="_blank"> <img alt="last release" src="https://img.shields.io/github/v/release/Yu-Leo/sierpinski-triangle?style=for-the-badge&labelColor=090909"></a>
  <a href="#" target="_blank"> <img alt="last commit" src="https://img.shields.io/github/last-commit/Yu-Leo/sierpinski-triangle?style=for-the-badge&labelColor=090909"></a>
  <a href="#" target="_blank"> <img alt="commit activity" src="https://img.shields.io/github/commit-activity/m/Yu-Leo/sierpinski-triangle?style=for-the-badge&labelColor=090909"></a>
</p>

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
      git clone https://github.com/Yu-Leo/sierpinski-triangle.git
      cd sierpinski-triangle
      ```
   * Вариант 2 - [Скачать ZIP](https://github.com/Yu-Leo/sierpinski-triangle/archive/refs/heads/main.zip)
4. Подключить SFML к проекту ([мой туториал](https://github.com/Yu-Leo/knowledge-base/blob/main/SFML-VisualStudio2019/README.md))
5. Скомпилировать и запустить `./sierpinski-triangle/main.cpp`

<a id="chapter-2"></a>

## :camera: Демонстрация

![demo](./docs/img/demo.jpg)

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

