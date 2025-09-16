#include "comment_removal_comb.h"
#include "extra_newline_removal_comb.h"
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
  int remove_comment_flag = 0;
  int remove_extra_newline_flag = 0;
  int inplace_flag = 0;
  char *files[100]; // Mostly you must know  char *file is the pointer to the
                    // string ( but by default that is the pointer decayed to
                    // the  first character only , cause string is the array of
                    // character contigous so would be easy )

  // Where as  char *files[100] you have created the pointer of char type to 100
  // places which would be string (character of array i would say )

  int file_count = 0;

  if (argc < 2) {
    fprintf(
        stderr,
        "Usage %s [--comment] [--collapse-newline] [--inplace] <files..> \n",
        argv[0]);
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--comment") == 0)
      remove_comment_flag = 1;
    else if (strcmp(argv[i], "--collapse-newline") == 0)
      remove_extra_newline_flag = 1;
    else if (strcmp(argv[i], "--inplace") == 0)
      inplace_flag = 1;
    else
      files[file_count++] = argv[i];
  }

  // loop over the files / implement the options to them using flags
  for (int i = 0; i < file_count; i++) {

    FILE *input = fopen(files[i], "r");
    if (!input) {
      fclose(input);
      perror("fopen");
      continue;
    }

    // here i am  creating some thing like if the user used inplace option so we
    // dont overwrite in current one maybe if he using same file somewhere , he
    // can check it and just rename it ,  by default it would be something _new
    // at end
    char outname[512];
    if (inplace_flag) {
      snprintf(outname, sizeof(outname), "%s.tmp", files[i]);
    } else {
      snprintf(outname, sizeof(outname), "%s_new", files[i]);
    }

    FILE *output = fopen(outname, "w+");
    if (!output) {
      perror("fopen");
      fclose(input);
      fclose(output);
      continue;
    }

    if (remove_comment_flag && remove_extra_newline_flag) {

      // it is bit  different , i also amazed with this , it is like you create
      // some kind of the temporary file in the temp/ directory and you open the
      // the file with some fd descriptor used by the process , you unlink the
      // file (removed the directory name) now  inode is there but with nothing
      // pointing to , until the process is running with the fd inode is there
      // after that kernel will kill inode and fd is destroyed when it is done
      FILE *temp = tmpfile();
      if (!temp) {
        fclose(input);
        fclose(output);
        perror("tempfile");
        continue;
      }
      comment_removal(input, temp);
      rewind(temp);
      newline_remover(temp, stdout);
      fclose(temp);
    }

    else if (remove_extra_newline_flag) {
      newline_remover(input, stdout);
    }

    else if (remove_comment_flag) { //  Both
      comment_removal(input, stdout);
      //
    }
    fclose(input);
    fclose(output);

    if (inplace_flag) {
      if (rename(outname, files[i]) != 0)
        perror("rename");
    }
  }
  return 0;
}
