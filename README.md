# C code to Source engine alias
The goal of this project is to make a compiler to compile simple c code to source engine aliases.

## How this works
We can control program flow by "rewriting" it in real time, this means that every if statement will be changed to do something different, where it means to do something, or not to do something.   
if we take an alias and make it run another alias that does things, then this expression would be true. If we were to not do something, we can make the alias point to another that does nothing.   

This has some limitations, that being, wherever a variable is used, every conditional needs to be changed at runtime.
This is really slow, but it still has some use.   
You may want to write some conditionals or functions in aliases, but that takes lots of time and ends up with a script that is hard to understand.    
Here is where we come in. by making a simple source code compiler, we can do all this work for you, saving you time and making your scripts POWERFUL!   

## The goal
The goal is to make a c like language that compiles into alias scripts.   
This is more of a rough sketch of what c is, but there are alot of limitations with alias scripting but those can still be worked around.   
There will be no "heap" and every variable is static and changes flow of code when changed.   
Thus you should keep the amount of variables as little as possible.
Another is conditionals, they will mostly be comparing bools, and not actual conditions. this is a major TODO
