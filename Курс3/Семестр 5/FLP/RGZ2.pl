% �������� �����
read_file(File, Text) :-
    open(File, read, Stream),
    read_line_to_codes(Stream, Codes),
    close(Stream),
    atom_codes(Text, Codes).

% ������������ ���� � �������� �������
reverse_words(Text, ReversedText) :-
    atomic_list_concat(Words, ' ', Text),
    reverse(Words, ReversedWords),
    atomic_list_concat(ReversedWords, ' ', ReversedText).

% ���������� ���������� � ����
save_file(File, Text) :-
    open(File, write, Stream),
    write(Stream, Text),
    close(Stream).

% ������� �������
main :-
    read_file('input.txt', Text),
    reverse_words(Text, ReversedText),
    save_file('output.txt', ReversedText).

