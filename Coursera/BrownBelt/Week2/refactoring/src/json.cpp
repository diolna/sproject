#include "json.h"
using namespace std;



Json::Node::Node(vector<Json::Node> array) : as_array(move(array)) {
}

Json::Node::Node(map<string, Json::Node> map) : as_map(move(map)){
}

Json::Node::Node(int value) : as_int(value) {
}

Json::Node::Node(string value) : as_string(move(value)) {
}

const vector<Json::Node>& Json::Node::AsArray() const {
  return as_array;
}

const map<string, Json::Node>& Json::Node::AsMap() const {
  return as_map;
}

int Json::Node::AsInt() const {
  return as_int;
}

const string& Json::Node::AsString() const {
  return as_string;
}

Json::Document::Document(Json::Node root) : root(move(root)) {
}

const Json::Node& Json::Document::GetRoot() const {
  return root;
}

Json::Node LoadNode(istream& input);

Json::Node LoadArray(istream& input) {
  vector<Json::Node> result;

  for (char c; input >> c && c != ']'; ) {
    if (c != ',') {
      input.putback(c);
    }
    result.push_back(LoadNode(input));
  }

  return Json::Node(move(result));
}

Json::Node LoadInt(istream& input) {
  int result = 0;
  while (isdigit(input.peek())) {
    result *= 10;
    result += input.get() - '0';
  }
  return Json::Node(result);
}

Json::Node LoadString(istream& input) {
  string line;
  getline(input, line, '"');
  return Json::Node(move(line));
}

Json::Node LoadDict(istream& input) {
  map<string, Json::Node> result;

  for (char c; input >> c && c != '}'; ) {
    if (c == ',') {
      input >> c;
    }

    string key = LoadString(input).AsString();
    input >> c;
    result.insert({move(key), LoadNode(input)});
  }

  return Json::Node(move(result));
}

Json::Node Json::LoadNode(istream& input) {
  char c;
  input >> c;

  if (c == '[') {
    return LoadArray(input);
  } else if (c == '{') {
    return LoadDict(input);
  } else if (c == '"') {
    return LoadString(input);
  } else {
    input.putback(c);
    return LoadInt(input);
  }
}

Json::Document Load(istream& input) {
  return Json::Document{LoadNode(input)};
}


