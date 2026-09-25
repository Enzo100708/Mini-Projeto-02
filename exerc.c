#include <stdio.h>
int strleng(char *s)
{
    int i = 0;
    while (s[i++] != '\0')
        ;
    return i - 1;
}
void Inverter(char s[])
{
    int tamanho = 0;
    while (s[tamanho] != '\0')
    {
        tamanho++;
    }
    int comeco = 0;
    int fim = tamanho - 1;
    char period;

    while (comeco > fim)
    {
        period = s[comeco];
        s[comeco] = s[fim];
        s[fim] = period;
        comeco++;
        fim--;
    }
}
void deslocamento(char s[], int d[])
{
    int n;
    scanf("%d", &n);
    int tamanho = 0;
    while (s[tamanho] != '\0')
    {
        tamanho++;
    }
    if (n == 0)
    {
        return;
    }
    int comeco = 0;
    int fim = tamanho - 1;
    char period;
    int i, j;
    n = n % tamanho;
    for (i = 0; i < n; i++)
    {
        period = s[tamanho - 1];
        period = d[tamanho - 1];
        for (j = 0; i < n; j--)
        {
            s[j] = s[j - 1];
            d[j] = d[j - 1];
        }
    }
    period = s[0];
    period = d[0];
}
void inverterCaixa(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        { // verifico se e letra
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;
            else if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }
    }
}
void Rotacionar(char s[])
{
    int n;
    scanf("%d", &n);
    int tamanho = 0;
    while (s[tamanho] != '\0')
    {
        tamanho++;
    }
    if (n == 0)
    {
        return;
    }
    int j, i;
    char period;
    n = n % tamanho;
    for (i = 0; i < n; i++)
    {
        period = s[tamanho - 1];

        for (j = 0; j < n; j--)
        {

            s[j] = s[j - 1];
        }
    }
    s[0] = period;
}
void trocarMetades(char *s)
{
    int tamanho, i, j, k;
    tamanho = strleng(s);
    char sCp[tamanho + 1];
    for (i = 0; i < tamanho / 2; i++)
        sCp[i] = s[i]; // copiar o inicio
    sCp[i] = '\0';
    if (tamanho % 2 == 0)
    {
        j = tamanho / 2;
        for (i = 0; i < tamanho / 2; i++)
        {
            s[i] = s[j];
            j++;
        }
        k = 0;
        for (i = tamanho / 2; sCp[k] != '\0'; i++)
        {
            s[i] = sCp[k];
            k++;
        }
    }
    else
    {
        j = tamanho / 2 + 1;
        for (i = 0; i < tamanho / 2; i++)
        {
            s[i] = s[j];
            j++;
        }
        k = 0;
        for (i = tamanho / 2 + 1; sCp[k] != '\0'; i++)
        {
            s[i] = sCp[k];
            k++;
        }
    }
}
int main()
{
    char str[10001];
    int n;
    scanf("%[^\n]%*c", str);
    while (n != 0)
    {
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            Inverter(str);
            break;
        case 2:

            break;
        case 3:
            deslocamento(str, str);
            break;
        case 4:
            inverterCaixa(str);
            break;
        case 5:
            Rotacionar(str);
            break;
        case 6:

            break;
        }
    }
    printf("%s\n", str);
    return 0;
}