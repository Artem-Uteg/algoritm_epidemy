Алгоритм

Воспользуемся жадным алгоритмом:
1. Все вершины со степенью 1, изначально заражены, т.к. их не могут заразить соседи (пункт 2 задачи).
2. Мы перебираем все вершины и выбираем ту, при заражении которой у нас станет наибольшее количество зареженных соседей, если таких вершин несколько, мы выбираем любую.
3. Статус вершин после заражения одной из них проверяем DFS и если возможно ставим заражение соседям (пункт 2 задачи).
4. Алгоритм идет до полного заражения всего графа.

Корректность жадного алгоритма и оценка точности решения:
Точность ответа данного жадным алгоритмом не привосходит оптимальное больше чем в 2 раза:
Для доказательства этого факта рассмотрим произвольный зараженный граф T, являющийся подграфом G и вершину v, которое не принадлежит T, вершину u, которое принадлежит оптимальному решению. Обозначим через w(v) количество вершин, который мы можем заразить после заражения данной вершины. Рассмотрим два случая:

1. Если w(v) >= w(u), то жадный алгоритм выберет на первом шаге вершину v, и поэтому в результате получится граф, которое содержит v и не содержит u. В этом случае количество вершин которые мы можем заразить не меньше чем оптимальное количетво, увеличенное на количество вершин которое мы можем заразить с помощью верщины v. 
2. Если w(v) < w(u), то жадный алгоритм выберет на первом шаге вершину u, и поэтому в результате получится граф, которое содержит u и не содержит v. Получивщийся является оптимальным из определения вершины u. 

Таким образом, жадный алгоритм находит граф возможного заражения, который не более чем в два раза отличается от оптимального.

Ассимптотика: O(n^2).


Запуск программы:
g++ algoritm.cpp
./a.out
 //Вводим тестовый набор данных
 //Получаем ответ


 В test лежат несколько тестов с ответами, которые выдала программа.

