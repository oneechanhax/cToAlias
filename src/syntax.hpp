
/*
 *
 * This file contains stuff to make the syntax work in a data form
 *
 */
#pragma once

#include <string>

// Use this to refrence the source to parts of the code
class SyntaxRefrence {
public:
SyntaxRefrence(int _line_num, const std::string& _line_str, const std::string& _component) :
  line_num(_line_num), line_str(_line_str), component(_component){}
void Note(std::string note); // To place notes
void Infringe(std::string error, std::string note); // Use to call out syntax problems
void InfringeNote(std::string error, const SyntaxRefrence& note_ref, std::string note); // Same as above but also notes
const std::string& GetComponent() {return component;}
const std::string& GetType() {return type;}
protected:
std::string type; // Used internally to tell what this is
private:
int line_num;
std::string line_str;
std::string component;
};

// This represents a typename
class SyntaxTypename : public SyntaxRefrence {
public:
  SyntaxTypename(SyntaxRefrence ref) : SyntaxRefrence(ref) {type = "typename";}
};

// A variable
class SyntaxVariable : public SyntaxTypename {
public:
  SyntaxVariable(SyntaxTypename ref) : SyntaxTypename(ref) {type = "variable";}
};

// TODO brace enclosed
class SyntaxBraceEnclosed {
public:

};

// This represents a function that will perform an action in a braced enclosed area
class SyntaxFunction {
public:
  // declare a function
  SyntaxFunction(SyntaxTypename _ret_name, SyntaxRefrence _name) : ret_name(_ret_name), name(_name) {}
  // define a function
  SyntaxFunction(SyntaxTypename _ret_name, SyntaxRefrence _name, SyntaxBraceEnclosed _func_contents) :
    SyntaxFunction(_ret_name, _name) {this->Define(_func_contents);}
  void Define(SyntaxBraceEnclosed _func_contents) {
    if (this->defined) {
      //_func_contents.Infringe("Function already defined.");
      name.Note("Defined here.");
      exit 1;
    }
    func_contents = _func_contents;
  }
private:
  const SyntaxTypename ret_name;
  SyntaxRefrence name;
  bool defined = false;
  SyntaxBraceEnclosed func_contents;
};
