#include "shell.h"

/**
 * __history - displays the history list
 * @info: info params from info struct
 *  Return: 0 on success
 */
int __history(info_t *info)
{
    print_list(info->history);
    return (0);
}

/**
 * unset_alias - un-sets alias to string
 * @info: params from info struct
 * @str: the string alias
 * Return: Always 0 on success
 * 1 on error
 */
int unset_alias(info_t *info, char *str)
{
    char *p, c;
    int return_val;

    p = _strchr(str, '=');
    if (!p)
        return (1);
    c = *p;
    *p = 0;
    return_val = delete_node_at_index(&(info->alias), get_node_at_index(info->alias, node_starts_with(info->alias, str, -1)));
    *p = c;
    return (return_val);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success
 * 1 on error
 */
int set_alias(info_t *info, char *str)
{
    char *p;

    p = _strchr(str, '=');
    if (!p)
        return (1);
    if (!*++p)
        return (unset_alias(info, str));

    unset_alias(info, str);
    return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @alias_node: the alias node
 * Return: Always 0 on success
 * 1 on error
 */
int print_alias(list_t *alias_node)
{
    char *p = NULL, *a = NULL;

    if (alias_node)
    {
        p = _strchr(alias_node->str, '=');
        for (a = alias_node->str; a <= p; a++)
            _putchar(*a);
        _putchar('\'');
        _puts(p + 1);
        _puts("'\n");
        return (0);
    }
    return (1);
}

/**
 * __alias - mimics the alias builtin (man alias)
 * @info: info params from info struct
 *  Return: Always 0
 */
int __alias(info_t *info)
{
    int i = 0;
    char *p = NULL;
    list_t *node = NULL;

    if (info->argc == 1)
    {
        node = info->alias;
        while (node)
        {
            print_alias(node);
            node = node->next;
        }
        return (0);
    }
    for (i = 1; info->argv[i]; i++)
    {
        p = _strchr(info->argv[i], '=');
        if (p)
            set_alias(info, info->argv[i]);
        else
            print_alias(node_starts_with(info->alias, info->argv[i], '='));
    }

    return (0);
}
