size_t  strlen(const char *s)
{
    size_t length;
    while (*s != '\0')
    {
        length ++;
        s ++;
    }
    return (length);
}
