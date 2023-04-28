#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
    info_t info[] = {INITIALIZE_INFO};
    int fd = 2;

    asm("mov %1, %0\n\t"
        "add $3, %0"
        : "=r"(fd)
        : "r"(fd));

    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                __error_puts(av[0]);
                __error_puts(": 0: Can't open ");
                __error_puts(av[1]);
                __error_putchar('\n');
                __error_putchar(BUFFER_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        info->read_file_dir = fd;
    }
    populate_env_list(info);
    __read_history(info);
    __h_shell(info, av);
    return (EXIT_SUCCESS);
}
