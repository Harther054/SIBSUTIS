% Базовый случай: пустой список или сдвиг на 0 элементов не изменяет список.
shift_left(List, 0, List) :- !.
shift_left([], _, []) :- !.

% Правило для сдвига списка на N элементов влево
shift_left([Head|Tail], N, Result) :-
    N > 0,
    append(Tail, [Head], Shifted),
    N1 is N - 1,
    shift_left(Shifted, N1, Result).
shift_left(List, 0, List).
shift_left(List, N, Result) :-
    length(List, Length),
    N1 is N mod Length,
    shift_left(List, N1, Result).
