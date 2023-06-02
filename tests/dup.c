#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // Save the original file descriptor of stdout
    int original_stdout_fd = dup(STDOUT_FILENO);

    // Redirect stdout to a file
    int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    dup2(file_fd, STDOUT_FILENO);

    // Perform operations that generate output
    printf("This will be written to output.txt\n");

    // Restore stdout to its original state
    dup2(original_stdout_fd, STDOUT_FILENO);

    // Close the duplicated file descriptor
    close(original_stdout_fd);

    // Output will now be printed to the console
    printf("This will be printed to the console\n");

    return 0;
}
