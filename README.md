# Minishell
Creating a simple shell

**Не обрабатываем**
STDERR is redirect to STDOUT: redirected to /dev/null,
effectually redirecting both STDERR and STDOUT to /dev/null         
echo 'hello' > /dev/null 2>&1

**Syntax error**
- [*] empty string only separators)
Строка только с одним токеном SEP, вовзращает управление.
- [*] Строка с отсутствующими токенами только с одним токеном SEP между пайпами
- [*] Отсутствие токенов WORD, QUOTE, DOUBLE_QOUTE после редиректа (возможен SEP между)


**expand $**
- [] hello$USER
- [] hello$USER$USER
- [] $\0 
- [] $?
- [] ${USER} - фигурные скобки
something else?


**Notes**

Может не быть названия команды (=null)

bash-3.2$ echo privet infile >
bash: syntax error near unexpected token `newline'

wc << end


bash-3.2$ ls | cat << end | wc
> hello
> end
       1       1       6
bash-3.2$ ls | cat << end | wc << end2
> end
> end2
       0       0       0

  > out | ls (зависает) 