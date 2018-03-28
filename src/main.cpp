
/*
 *
 * Entry point
 *
 */

#include <vector>
#include <string>
#include <iostream>

int main(int argsN, const char** argsS) {
  // args
  std::vector<std::string> inFiles;
  // Handle args
  for (int i = 0; i < argsN; i++) {
    if (argsS[i][0] == '-') {
      puts("Proper args disabled, TODO FIX\n");
      return 1;
      switch(argsS[i][1]){
      case 'O':
        // TODO optimize
        break;
      default:
        printf("Unknown argument: \"%s\"", argsS[i]);
        return 1;
      }
    // Intake of files
    } else {
      inFiles.push_back(argsS[i]);
    }
  }

  // Check args
  if (inFiles.empty()){
    puts("Missing files to compile!\n");
    return 1;
  }

  return 0;
}
