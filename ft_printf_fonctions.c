#include "ft_printf.h"

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
    int i;

    i = 0;
    if (s == NULL)
    {
        i += ft_putstr("(null)");
    }
    else{
        while (s[i])
        {
            ft_putchar(s[i]);
            i++;
        }
    }
    return (i);
}

int ft_putnbr_hexa(unsigned long long nb, char *base)
{
    int total;

    total = 0;
    if (nb >= 16)
    {
        total += ft_putnbr_hexa(nb / 16, base);
        total += ft_putnbr_hexa(nb % 16, base);
    }
    else 
        total += ft_putchar(base[nb]);
    return (total);
}

int ft_putnbr(long long nb)
{
    int total;

    total = 0;
    if (nb < 0)
    {
        total += ft_putchar('-');
        total += ft_putnbr(nb * -1);
    }
    else if (nb >= 10)
    {
        total += ft_putnbr(nb / 10);
        total += ft_putnbr(nb % 10);
    }
    else 
        total += ft_putchar(nb + '0');
    return (total);
}

int ft_putnbr_u(unsigned int nb)
{
    int total;

    total = 0;
    if (nb >= 10)
    {
        total += ft_putnbr(nb / 10);
        total += ft_putnbr(nb % 10);
    }
    else 
        total += ft_putchar(nb + '0');
    return (total);
}