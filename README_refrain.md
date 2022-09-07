Токен - условная логическая единица. Мы будем различать двойные и одинарные кавычки, и это все будет разными токенами
envp_list содержит самую новую информацию о переменной окружения

односвязный список:
key1	key2
	->
val1	val2

1. Typedef

Определим указатели на функции builin'ов, чобы потом их можно было хранить в массиве, который будет состоять из этих указателей

typedef int (&t_builtin_ptr)(t_list *, t_info *) 

&t_builtin_ptr - указатель на функцию builtin'a, сможем обратиться к нему и передать 2 параметра: info - общая структура, которую определим чуть позже и односвязный список аргументов для данного builtin'a 
Внутри односвязаного списка будет лежать пара (элемент не просто будет указывать на что-то, а будет указывать на пару ключ-значение key-val)
Односвязный список будет состоять из пар (один элемент - это пара). Внутри связного списка будет 2 void *: один на ключ, другой на значение

key - void *, можем положить что угодно

t_info 
Внутри t_info будет массив указателей на функции builtin'a, чтобы их потом вызывать
{
t_builin_ptr builtins[7] (здесь не ставится указатель, т.к. в прототипе изначально прописан указатель)

char    reserved_words[7] (названия наших builtin'ов, их 7 по сабджекту). Массив, элемент которого строка, и строка, например, env. Т.е. мы будем сравнивать первый аргумент, который мы получили в команде, когда мы будем искать, какой builtin исполнить, мы будем сравнивать со словами в массиве, совпадает ли на 100% с тем, что нам подали. 

char **envp - массив переменное окружение, который мы будем постоянно изменять

t_list	envp_list  - односвязный список, который будет в себе содержать пару key/val, будет отображать текущее состояние переменной окружение. Если операции над листом не были произведены, не нужно пересобирать массив

char	 envp_f; флаг, 1 - если нужно пересобрать перебенную, если 0 - можно передать указатель на массив

char	exit_t	флаг выхода; в builtin'e, когда вызываем exit, мы должны поставить exit_t в 0, т.е. не нужно больше выполнять зацикливание (чтение команды, обработка, исполнение). После исполнения exit_t будет в нуле и мы выйдем из минишелла, освободив при этом ресурсы

int	status отвечает за исполнение команды. все наши команды ьудут исполняться в подпроцессах, за исключением builtin'ов. След-но, сигналы будут обрабатываться иным способом, т.е. мы не будем отдавать глобальную переменную в handler сигналов, а мы будем смотреть статус выхода процесса. Не нужно делать переменную status глобальной

можно объявить здесь еще 2 листа (либо дописать в мейнике): лист токенов и лист групп либо команд
можно пропустить шаг группировки на логические группы и сразу группировать на пайпы. Смотрим, есть ли пайп в команде, то нужно его проверить на синтаксис пайплайна после группировки
}

WIFSIGNALED(sig) удобный способ узнать, завершился ли процесс сигналом

waitpid(pid, &sig, 0) &sig - основная информация, а именно статус выхода

В мейне все просто: сначала инициализируемся
Этапы мейна:
1. инициализация init
определение всех наших указателей, всех наших слов
первичная сборвка envp и первичное заполнение envp_list
2. цикл пока не нужно выходить, мы обрабатываем все, что внутри цикла
while (!exit_t)
Внутри цикла: 
2.1. чтение строки (помогает readline)
делаем readline, если считали не пустую строку (вернулся не нулевой указатель), мы добавляем его в историю и возвращаем просто как строку
ft_readline - считать строку (просто readline не обновит историю)
//s = realine(p)

char *ft_readline (char *) здесь указать prompt: bash, minishell; также вернуть указатель на строку (его нужно будет освободить)
внутри ft_realine вызов библиотечной readline (что-то вернет, если строка не пустая, нужно добавить в историю, даже абракадабру)

if(s)
	add_history(s)
	return s

2.2. lexer 
обработка строки
сначала нужно разбить на токены в лексере

2.3. parser

2.4. executor исполнение 

3. destruct освободить все ресурсы

2. Структуры
3. Контейнеры
4. лексер, парсер, исполнитель

В лексере будем определять типы токенов, и эти типы токенов будут превращаться в числа (например, 1 - разделитель)& Тогда данный элемент имеет тип разделитель и значение val
Все, что в двойных кавычках, будет считаться токеном

WTERMSIG - узнать номер сигнала

Лексер - наш модуль, который будет превращать просто строку в набор логических токенов
Токеном может быть что угодно
Главное само превращение строки в набор каких-то логических элементов
Лексер из набора символов превратит в токены

Например, до лексера просто набор символов:
cat > file | cat < file 
пробел тоже токен

Типы токенов (можно задать как константы через define, лучше, чтобы это были числа, чтобы поместить в void *):
1. separator разделитель (любое пустое место, все, что считается isspace)
Если между 2мя разными токенами нет разделителя, то после они склеятся, будет 1 токен
После склейки токенов не может происходить раскрытие переменных окружения
2. обычное слово WORD
Когда встречаются символы без кавычек и те, которые не считаются специальными
@ , например, будет тоже считаться обычным словом
3. поле FIELD одинарные кавычки ' 
4. EXP_FIELD кавычки, которые раскрываются "
5. REDIR_OUT перенаправление в файл > 
6. REDIR_IN перенаправление из файлы <
7. REDIR_APPEND дописывание в файл >>
8. REDIR_INSOURCE чтение из heredoc'a <<
9. PIPE токен пайпа |
для бонусов:
10. IF_AND если то &&
11. IF_OR если или ||
12. PARN_L токены скобок, чтобы следить за уровнем вложенности, правая скобка (
13. PARN_R левая скобка )

После того, как мы разбили все на токены, мы переходим к парсингу токенов

У парсера следующие этапы:
1. разбиение на логические группы (если с бонусами)
2. проверка правильности логических групп
3. раскрытие скобок в логической группе, раскрытие слов word expansion
как выглядит логическая группировка: у нас это связный список, идем по связному списку до этого токена, и это будет первой группой
 
После $ либо еще одни $, либо ?, либо название переменной, которую нужно раскрыть

$ - id процесса первичного шелла (когда в первый раз запустили минишелл, получится какой-то id, и он запишется в $)
? - статус выхода последней команды

После раскрытия слова для бонусов его нужно еще проверить на открытие звездочки
Даже если в одинарных кавычках была звездочка, может произойти раскрытие именно звездочки

Надо будет построить 2 массива: сверху будет паттер, сбоку строка
Раскрытие будет успешным, если из левого верхнего угла дойти до правого нижнего угла и там будет 1 (google pattern matching)

   
5. сигналы и 
6. обработка внутренних команд (builtin)
Всего 7

нужно посмотреть, пайплайн или нет
если не пайплайн, то нужно исполнить это как обычную команду (тут 2 варианта: builtin или не builtin). Если не builtin, запускаем доп. дочерний процесс и в нем ремапим fd-шники и запускаем его. Если это builtin, то мы не можем запустить его как подпроцесс. Делаем псевдоремапинг (будем у нашего процесса и ввод, и вывод перенаправлять, но потом мы его восстановим)

Если это пайплайн, то builtin'ы исполняются каждый в своем процессе. Если в пайплайне мы сделаем несколько экспортов, и присвоили новые значения переменным, то в окружении шелла они не изменятся. В то же время просто экспорт изменит шелл

Нужно 2 функции: 
1. функция на запуск builtin'a внутри нашего шелла
2. функция на запуск builtin'a внутри дочернего процесса

Команда без пайпов - исполняем ее в переменное окружение
builtin'у подается список аргументов и указатель на информацию (t_info)

(t_llist args, t_info *info)

Если кол-во аргументов для exit'a больше 2, то exit говорит, что это неправильное использование и ставит статус выхода 1
статус 255 - если вместо числа подана строка
статус от 0 до 255
если число статуса очень большое, вывод будет %256

echo -n

read command
|
lexer (разбиение на токены)
|
parser (анализ токенов и раскрытие кавычек и т.д.)
|
execute (потом запускаем ее)
|
post actions (действия 