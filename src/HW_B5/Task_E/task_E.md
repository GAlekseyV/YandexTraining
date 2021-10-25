# E. Сумма трёх

|                     |                                    |
| ------------------- | ---------------------------------- |
| Ограничение времени | 15 секунд                          |
| Ограничение памяти  | 256Mb                              |
| Ввод                | стандартный ввод или threesum.in   |
| Вывод               | стандартный вывод или threesum.out |

Даны три массива целых чисел A,B,C и целое число S.

Найдите такие $i,j,k,$ что $A_i+B_j+C_k=S$.

## Формат ввода

На первой строке число $S (1≤S≤10^9)$. Следующие три строки содержат описание массивов A,B,C в одинаковом формате: первое число задает длину n соответствующего массива $(1≤n≤15000)$, затем заданы n целых чисел от 1 до $10^9$ — сам массив.

## Формат вывода

Если таких i,j,k не существует, выведите единственное число −1. Иначе выведите на одной строке три числа — i,j,k. Элементы массивов нумеруются с нуля. Если ответов несколько, выведите лексикографически минимальный.

## Пример 1

| Ввод  | Вывод |
| :---: | :---: |
|   3   | 0 1 1 |
| 2 1 2 |
| 2 3 1 |
| 2 3 1 |

## Пример 2

| Ввод  | Вывод |
| :---: | :---: |
|  10   |  -1   |
|  1 5  |
|  1 4  |
|  1 3  |

## Пример 3

|   Ввод    | Вывод |
| :-------: | :---: |
|     5     | 0 1 2 |
| 4 1 2 3 4 |
|  3 5 2 1  |
| 4 5 3 2 2 |