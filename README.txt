biblioteka głownie używana do debugowania wycieków pamięci czy sprawdzania zachowania programu przy ograniczonej liczbie bajtów

Biblioteke można na bierząco dodawać i usuwać (includować) nie powinna ona zmienić działania programu w żaden sposób

Zredefiniowane funkcje(używać tak jak stare):
malloc
calloc
free
realloc

Dodatkowe funkcje
s_echo(int) - ustawia czy SmartPointers ma cokolwiek wypisywać na konsole (0=false)
s_set_allocation_limit(size_t) - ustawia limit bajtów jaki program może zaalokować
s_free_all() - czyści wszystkie zaalokowane obszary pamięci
s_show_blocks() - Pokazuje aktualnie zaalokowane bloki w konsoli
s_status_of_allocation() - Pokazuje aktualny stan pamięci, Zajęte miejsce/Max miejsce

Program dodatkowo prócz wykrywania wycieków automatycznie wszystkie wycieki czyści, więc w konsekwencji tego nie trzeba
w ogóle w programie używać free, natomiast jest wskazane żeby nie nadużywać tego, czy też nie wrzucać tego wprost do dante
bo plagiat lub tłumaczenie się jak to działa

w SmartPointers.h jest ustawiony POINTER_LIMIT na 2^16, sądze że to wystarczająco natomiast można tą wartość zmienić
definuje ona ile wskaźników naraz może zapamiętać program

Blbioteka default'owo używa około 1MB pamięci i nie wpływa znacząco na prędkość programu, możliwe optymalizacje w przyszłości
Wszystkie metadane bilbioteki nie są alokowane dynamicznie, by nie wpływać na dynamiczną alokacje programu

używanie innych metod allokacji niż 4 zredefiniowane funkcje nie jest wykrywane bądź obsługiwane przez biblioteke

w main.c przykładowe użycie

jeśli jakaś dodatkowa funkcjonalność się przyda, lub jakiś bug jest znaleziony, śmiało pisać

Rozważam dodanie wykrywania/obsługi wycieków plików