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

    while (comeco < fim)   
    {
        period = s[comeco];
        s[comeco] = s[fim];
        s[fim] = period;
        comeco++;
        fim--;
    }
}

void deslocamento(char *s, int n)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = 'a' + (((s[i] - 'a') + n) % 26 + 26) % 26;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = 'A' + (((s[i] - 'A') + n) % 26 + 26) % 26;
        else if (s[i] >= '0' && s[i] <= '9')
            s[i] = '0' + (((s[i] - '0') + n) % 10 + 10) % 10;
    }
}

void trocarParesImpares(char *s)
{
    int i, j, k, tamanho, temp;
    tamanho = strleng(s);
    char sCp[tamanho + 1];
    for (i = 0; i < tamanho; i++)
        sCp[i] = s[i];
    sCp[i] = '\0';
    j = 1;
    k = 0;
    for (i = 0; sCp[i] != '\0' && s[k] != '\0'; i++)
    {
        if (i % 2 == 1)
        {
            s[k] = sCp[i];
            k += 2;
        }
        else
        {
            s[j] = sCp[i];
            j += 2;
        }
    }
    if (tamanho % 2 == 1)
        s[i] = '\0';
}

void inverterCaixa(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        { 
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;
            else if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }
    }
}

void Rotacionar(char s[], int n)
{
    int tamanho = 0;
    while (s[tamanho] != '\0')
    {
        tamanho++;
    }
    if (tamanho == 0)
        return;

    n = n % tamanho;
    if (n < 0)
        n += tamanho; 
    if (n == 0)
        return;

    int i, j;
    char period;
    for (i = 0; i < n; i++)
    {
        period = s[tamanho - 1];
        for (j = tamanho - 1; j > 0; j--)
        {
            s[j] = s[j - 1];
        }
        s[0] = period;
    }
}

void trocarMetades(char *s)
{
    int tamanho, i, j, k;
    tamanho = strleng(s);
    char sCp[tamanho + 1];
    for (i = 0; i < tamanho / 2; i++)
        sCp[i] = s[i]; 
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
    int n, param;
    scanf("%[^\n]%*c", str);

    do
    {
        scanf("%d", &n);
        if (n == 0)
            break;

        switch (n)
        {
        case 1:
            Inverter(str);
            break;
        case 2:
            scanf("%d", &param);
            deslocamento(str, param);
            break;
        case 3:
            trocarParesImpares(str);
            break;
        case 4:
            inverterCaixa(str);
            break;
        case 5:
            scanf("%d", &param);
            Rotacionar(str, param);
            break;
        case 6:
            trocarMetades(str); 
            break;
        default:
            n = 0; 
            break;
        }
    } while (n != 0);

    printf("%s\n", str);
    return 0;
}
