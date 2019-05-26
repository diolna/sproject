#include "xml.h"

#include <string_view>
#include <iostream>
using namespace std;

pair<string_view, string_view> Split(string_view line, char by) {
	// функция Split приниамет два параметра по значпению. строку line и символ by/
	// в качестве возвращаемого значения возвращает пару строк.

  size_t pos = line.find(by);   // обьявляем переменную pos типа size_t которая указівает на
  // позицию символа (первое вхождение
  string_view left = line.substr(0, pos); //обьявлеем переменную left в которую помещаяе левую
  // подстроку с нулевого симола до найденой позиции pos

  if (pos < line.size() && pos + 1 < line.size()) {
	  // если позиция символа меньще длині строкки
    return {left, line.substr(pos + 1)};  // возвращаетм пару из єтой подстрки  и и оставшуючя
  } else {
    return {left, string_view()}; // иначе в качестве левого left a second пустой string_view
  }
}

string_view Lstrip(string_view line) {
	//функция lstrip в качестве входного параметра принимает строку line и возвращает тоже строку
  while (!line.empty() && isspace(line[0])) {
	  // пока строку не пуста и если символ 0 является  пробельным
    line.remove_prefix(1);  // сужает строку убирая префикс. пока первым символом является пробелом
    // убирает пробелі спереди
  }

  return line;
}

string_view Unquote(string_view value) {
  if (!value.empty() && value.front() == '"') {
    value.remove_prefix(1);
  }
  if (!value.empty() && value.back() == '"') {
    value.remove_suffix(1);
  }
  return value;
}

Node LoadNode(istream& input) {
  string root_name;
  getline(input, root_name); // извлекает символы из входного потока input в переменнню
  // root_name до обнаружения конца строки

  Node root(root_name.substr(1, root_name.size() - 2), {});  // обявляем переменную класса Node
  // root и инициализируем ее 2-мя значениями. 1- е єто имя узла определяестя как подстрока счит
  //считаной строки (с 1 по предпоследний элемент (убираем <>) и атрибуты пока без с нулевым занчением
  for (string line; getline(input, line) && Lstrip(line)[1] != '/'; ) {
	  // в цикле получаем стоки пока не дойдем до последней строки.
	  //проверяем это так убираем все пробелы и проверяем первый симовл. Если это '/' значит
	  //уже последняя строка

    auto [node_name, attrs] = Split(Lstrip(line), ' ');  // возвращаем две строки до и после пробела
    attrs = Split(attrs, '>').first;
    // обрезаем лишние данніх до >
    unordered_map<string, string> node_attrs;
    while (!attrs.empty()) {
    	// парсим следующим образом. отрезаем левую часть строки до первого пробела
    	// обрезаем левую часть до = тогда слева имя справа значение
      auto [head, tail] = Split(attrs, ' ');
      auto [name, value] = Split(head, '=');
      if (!name.empty() && !value.empty()) {
    	  // если имя и значения имеются сохраняем их.
        node_attrs[string(Unquote(name))] = string(Unquote(value));
      }
      // обновляем сторку перезаписіваем правую часть
      attrs = tail;
    }

    root.AddChild(Node(string(node_name.substr(1)), move(node_attrs)));
  }
  return root;
}

Document Load(istream& input) {
  return Document{LoadNode(input)};
}

Node::Node(
  string name, unordered_map<string, string> attrs
) : name(move(name)), attrs(move(attrs)) {
}

const vector<Node>& Node::Children() const {
	// константный метод Children класса Node с пустым списком входных параметров в качестве
	// возвращает константную ссылку на вектор элементов класса Node
  return children;
}

Document::Document(Node root) : root(move(root)) {

	//явный (см класс) конструктор класса Document принимает по значниюю один параметр класса Node
	// и Инициализирует поле root своего класса этим значением перемещая его командой move

}

const Node& Document::GetRoot() const {
	// Константрій метод класса Document с пустым списком входных параметров возвращает
	// константную ссілку класса Node
  return root;  // воздвращает константную ссылку на класс Node приватного поля root своего
  // класса Document

}

void Node::AddChild(Node node) {
  children.push_back(move(node));
}

string_view Node::Name() const {
  return name;
}

