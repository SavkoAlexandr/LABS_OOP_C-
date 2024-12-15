Все 7 лабороторных выполнены номером варианта - 12;
--------------------------------------------------------------------------------------------------------------------------------------------
1 Лабороторная,тема:
-
Шаблоны классов.
Выполнение заданий осуществляется без использования библиотеки STL. Создать шаблонный класс NameClass<T> и публичную вложенную структуру Node (имя класса указано в задании). 
Данный класс должен быть объявлен и определен в пространстве имен containers.
Структура Node должна содержать:

1)Публичное поле value типа T со значением, хранимым в данном элементе шаблонного класса.
2)Приватные поля для осуществления связи элементов в шаблонном классе.
3)Приватный конструктор(ы). Ничто кроме шаблонного класса NameClass не должно иметь возможности создания элементов типа Node.

Класс должен содержать:
1) конструктор по умолчанию, создающий экземпляр класса нулевого
размера;
2)Конструктор от std::initializer_list<T>.
3)Конструктор копирования и копирующий оператор присваивания.
4)Конструктор перемещения и перемещающий оператор присваивания.
5)операцию индексирования, возвращающую ссылку на соответствующий элемент экземпляра класса;
6)метод, добавляющий элемент в произвольную позицию экземпляра класса;
7)метод, удаляющий элемент из конца экземпляра класса (начала, произвольный элемент (в зависимости от задания)).
Добавить в класс другие методы, необходимые для реализации задания.

При выборе методов ориентироваться на методы, которые есть у шаблонных классов библиотеки STL.

В клиенте main() продемонстрировать использование этого класса для векторов, содержащих элементы типов int, double, string.
Для этого написать программу, демонстрирующую работу с этим
шаблоном для различных типов параметров шаблона.
Программа должна содержать меню, позволяющее осуществить проверку всех методов шаблона.

Разработать шаблонный класс MSet, для представления множества. Множество может хранить повторяющиеся элементы. Элементы в множестве хранятся отсортированными.

----------------------------------------------------------------------------------------------------------------------------------------------
2 Лабороторная,тема:
-
Обработка исключительных ситуаций.

Общая постановка. Даны два выражения Z1 и Z2. 
Написать функции для вычисления этих выражений с организацией обнаружения исключительной ситуации (например, деление на ноль) и ее обработки.
Передача аргументов в функции — по ссылкам. Для генерации исключения реализовать свой класс CustomException
который будет производным от Еxception и будет содержать: 
-строку с сообщенисм обошибке; 
-значение, которое привело к ошибке; 
- код ошибки
  
При обработке исключения показать использование класса CustomException.
В случае успеха значения 71 и Z2 должны быть приблизительно одинаковыми,

![image](https://github.com/user-attachments/assets/660c765d-3332-49d2-a719-b08ae03f57ac)
------------------------------------------------------------------------------------------------------------------------------------------------
3 Лабороторная,тема:
-
Использование параметризованных классов.

Выполнение заданий осуществляется без использования библиотек
memory и boost.

В классе должны быть объявлены необходимые конструкторы.
При реализации параметризованного класса предусмотреть методы, для обнуления указателя, обмена адресами для указателей, возвращения «сырого» указателя и др.
предусмотренные функционалом соответствующего библиотечного указателя.

В клиенте main() продемонстрировать использование этого класса для
векторов, содержащих элементы типов int, double, string.

Для этого написать программу, демонстрирующую работу с этим шаблоном для различных типов параметров шаблона. Программа должна
содержать меню, позволяющее осуществить проверку всех методов шаблона.

Создать шаблонный класс smart-указателя IPtrArr, реализующий
функционал intrusive_ptr, для работы с массивами.

-------------------------------------------------------------------------------------------------------------------------------------------------
4 Лабороторная,тема:
-
Шаблоны. Обработка исключительных ситуаций. Использование умных указателей.

Требуется создать шаблон некоторого целевого класса А.
В каждом варианте уточняются требования к реализации – указанием на применение некоторого серверного класса В. Это означает, что объект класса В используется как элемент класса А. 
В качестве серверного класса может быть указан либо класс, созданный программистом в рамках того же задания, либо класс стандартной библиотеки. 
Если не указан серверный класс или класс стандартной библиотеки, используется структура (класс) Node с типизированной переменной value, и указателями на предыдущий/следующий элемент.

![image](https://github.com/user-attachments/assets/14b47cd8-a217-4ece-9862-d09abbf6f398)

Если вместо серверного класса указан динамический массив, это означает, что для хранения элементов в целевом классе используется массив, размещаемый с помощью операции new.
Целевой класс должен содержать:
1) конструктор по умолчанию, создающий экземпляр класса нулевого
размера;
2)Конструктор от std::initializer_list<T>.
3)Конструктор копирования и копирующий оператор присваивания.
4)Конструктор перемещения и перемещающий оператор присваивания.
5)Добавить в целевой класс другие методы, необходимые для реализации задания.

При выборе методов ориентироваться на методы, которые есть у шаблонных классов библиотеки STL.
Во всех вариантах необходимо предусмотреть генерацию и обработку исключений для возможных ошибочных ситуаций.
Во всех вариантах в целевом классе для указателей необходимо предусмотреть использование созданного ранее шаблонного класса, реализующего умный указатель.
Проект должен состоять из нескольких файлов, в каждом файле реализация своего шаблонного класса (целевой класс, (серверный класс), класс обработчик исключений, класс умных указателей)
Во всех вариантах показать в клиенте main использование созданного целевого класса, включая ситуации, приводящие к генерации исключений.
Показать инстанцирование шаблона для типов int, doublе, std::string.

Для этого написать программу, демонстрирующую работу с этим шаблоном для различных типов параметров шаблона. Программа должна содержать меню, позволяющее осуществить проверку всех методов шаблона.
![image](https://github.com/user-attachments/assets/b15e6112-eeb9-4a7b-a964-6b38f9c4ef46)

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
5 Лабороторная,тема:
-
Потоки ввода вывода 

1)Напишите программу которая будет просить ввести строку символов ,
после этого он печатает её на экране 


1) все буквы в нижнем регистре ,
2) все буквы в большом регистре ,
3) все числа в строке выводить в HEX формате ,
4) вывод с заменой всех пробелов на символ #
Следующие задания требуется решить с привлечением текстовых
файлов.

Нужно написать функцию, с помощью которой подготовить входной
файл, записав в него 100 случайных целых чисел в диапазоне от -50 до +50 по
одному на строке. Сформировать выходной файл, преобразовав числа входного
файла.
2)Записать выходной файл, заменив все нули средним арифметическим.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
6 Лабороторная,тема:
-
Использование паттернов проектирования при разработке прикладных программ
Решение численных уравнений (шаблонный метод).

Задача
Используя паттерн шаблонный метод написать систему классов, которая
позволит применять различные сходящиеся итерационные алгоритмы, которые
все имеют схожий алгоритм:

1. Проверить некоторое уловие с некоторой точностью. Если
верно - вернуть текущий результат Xk
2. Если нет - вычислить следубщий член последовательности
предполагаемых результатов Xk+1 = g(Xk) и т.д.
В этой задаче необходимо численно решить одномерное
уравнение f(x)=0 на интервале [a, b] (в предположении, что на заданном
интервале есть только один корень). Приблизительно так. Хочется уметь это
делать разными методами:
 Метод хорд.
 Метод Ньютона.
Необходимо реализовать эти два алгоритма, используя паттерн
проектирования «Шаблонный метод».
Обратите внимание, что метод Ньютона кроме основной функции f требует
задания её производной f'. Учтите этот факт при разработке интерфейса классов.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
7 Лабороторная,тема:
-
Итераторы

Реализовать для своей программы, созданной в рамках лабораторной работы 4 , итераторы - 2 класса.

Один для обхода, например, положительных элементов коллекции, второй - отрицательных; или один для обхода коллекции в одну сторону, второй в другую (один для обхода дерева сверху вниз, второй слева направо). 
Предусмотреть исключительные ситуации и их обработку (например обращение к элементу коллекции, если она пустая).
Для обработки исключений использовать ранее реализованный класс CustomException. Создать общий интерфейс для работы с итераторами. 

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------












