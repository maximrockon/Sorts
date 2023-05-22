# Sorts
Мною на языке C++ было разработано консольное приложение sorts.exe, получающее целое число в качестве первого параметра (количество элементов в массиве) и строку “desc” в качестве второго параметра для сортировки по убыванию (сортировка по возрастанию осуществляется по умолчанию). Программа оценивает время работа трех алгоритмов эффективных сортировок (сортировка кучей, быстрая сортировки и сортировка слиянием) для трех массивов с различным расположением элементов (массив со случайными элементами, массив, отсортированный по возрастанию, и массив, отсортированный по убыванию). Все алгоритмы реализованы в качестве шаблонных методов класса Sort, для оценки времени используется класс Stopwatch. Для оптимизации кода в функции main() (устранение дублирования кода) используется класс Test.
