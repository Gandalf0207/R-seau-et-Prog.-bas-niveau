import subprocess


def execution(AlllistCmd):
    cpt = 0
    cpt2 = 0
    for packCmd in AlllistCmd:
        cpt2 += 1
        print("-----------------TD : ", cpt2, "-----------------")
        for cmd in packCmd:
            cpt+=1
            print("Test : ", cpt)

            try:
                resultat = subprocess.run(cmd, shell=True, capture_output=True, text=True)
                print(resultat.stdout.strip())
            except Exception as e:
                print("Execption : ", e)
        print("\n")


listCmd = [

    #--------TD1---------#
    [
    ],


    #--------TD2---------#
    [
    ],

    #--------TD3---------#

    [
        # mar. 3 févr. 21:16
        r'''find . -name readfile.c -exec bash -c "! grep -q fopen {} && grep -q 'open' {} && gcc {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # mer. 4 févr. 17:19
        r'''find . -name copy.c -exec bash -c "gcc -Wall -Werror {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # sam. 7 févr. 08:51
        r'''find . -name fonction-lireligne.c -exec bash -c "gcc -c -Wall -Werror {} && echo {} OK || echo {} ÉCHEC COMPIL." \; 2>/dev/null | sort''',

        # lun. 9 févr. 10:53
        r'''find . -name bigfich.c -exec bash -c "gcc {} && echo {} OK || echo {} ÉCHEC" \; | sort''',

        # lun. 9 févr. 11:39
        r'''find . -name puts.c -exec bash -c "gcc -Werror -c {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null''',

        # lun. 9 févr. 12:30
        r'''find . -name readfile.c -exec bash -c "gcc {} && ./a.out smells-like-teen-spirit.txt > /tmp/out.txt && cmp smells-like-teen-spirit.txt /tmp/out.txt >/dev/null && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # mar. 10 févr. 19:30
        r'''find . -name getchar.c -exec bash -c "gcc -c {} && echo {} OK || echo {} ÉCHEC COMPIL." \;''',

        # jeu. 12 févr. 07:27
        r'''find . -name copy.c -exec bash -c "gcc -Wall -Werror {} -o copier && ( [ -e copie-de-ls ] && rm -f copie-de-ls || true) && ./copier /usr/bin/ls copie-de-ls >/dev/null && cmp copie-de-ls /usr/bin/ls && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # jeu. 12 févr. 08:08
        r'''find . -name fonction-lireligne.c -exec bash -c "gcc -Wall -Werror testeur-nominal-lireligne.c {} && ./a.out < testeur-nominal-lireligne.c && echo {} OK || echo {} ÉCHEC" \;''',

        # jeu. 12 févr 09:52
        r'''find . -name bigfich.c -exec bash -c "gcc -Werror {} && (./a.out jours.txt mois.txt saisons.txt > out.txt && grep -q -e mois.txt out.txt && ! grep jours.txt out.txt && ! grep saisons.txt out.txt && echo {} OK || echo {} ÉCHEC) || echo {} ÉCHEC COMPIL." \; 2>/dev/null | sort''',

        # ven. 13 févr. 21:58
        r'''find . -name puts.c -exec bash -c "grep -qF 'int puts(const char* s) {' {} && gcc -Werror testeur-pour-puts.c {} && ./a.out 'We Are The Champions' | grep -q '^We Are The Champions$' && echo {} OK || echo {} ÉCHEC" \; | sort''',

        # dim. 15 févr. 09:51
        r'''find . -name readfile.c -exec bash -c "grep -q write {} && ! grep -q printf {} && echo {} OK || echo {} ÉCHEC" \; | sort''',

        # lun. 16 févr. 13:21
        r'''find . -name getchar.c -exec bash -c "echo -n {} '... '; gcc testeur-getchar.c {} && echo -n 'z' | ./a.out | grep -c 'z' | grep -q 1 && echo OK || echo ÉCHEC" \;''',

        # jeu. 19 févr. 09:31
        r'''find . -name copy.c -exec bash -c "gcc -Wall -Werror {} -o copier && ( [ -e copie-de-ls ] && rm -f copie-de-ls || true) && ./copier /usr/bin/ls copie-de-ls >/dev/null && chmod 0644 copie-de-ls && cmp copie-de-ls /usr/bin/ls && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort | grep OK''',

        # ven. 20 févr. 11:15
        r'''find . -name fonction-lireligne.c -exec bash -c "gcc -Wall -Werror testeur-erreur-lireligne.c {} && ./a.out && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # jeu. 26 févr. 14:23
        r'''find . -name bigfich.c -exec bash -c "gcc -Werror {} && (./a.out jours.txt mois.txt saisons.txt > out.txt && grep -q -e mois.txt out.txt && ! grep jours.txt out.txt && ! grep saisons.txt out.txt && echo {} OK || echo {} ÉCHEC) || echo {} ÉCHEC COMPIL." \; 2>/dev/null | sort | grep OK''',

        # sam. 7 mars 21:20
        r'''find . -name puts.c -exec bash -c "grep -qF 'int puts(const char* s) {' {} && gcc -Werror testeur-pour-puts.c {} && ./a.out 'We Are The Champions' | grep -q '^We Are The Champions$' && echo {} OK || echo {} ÉCHEC" \; | sort ./altunm/puts.c OK''',

        # jeu. 12 mars 23:32
        r'''find . -name readfile.c -exec bash -c "grep -q open {} && ! grep fopen {} && grep -q write {} && ! grep -q printf {} && gcc {} && ./a.out smells-like-teen-spirit.txt > /tmp/out.txt && cmp smells-like-teen-spirit.txt /tmp/out.txt >/dev/null && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort | grep OK''',

        # jeu. 19 mars 16:34
        r'''find . -name getchar.c -exec bash -c "echo -n {} '... '; gcc testeur-getchar.c {} && echo -n 'z' | ./a.out | grep -c 'z' | grep -q 1 && echo OK || echo ÉCHEC" \; | sort''',

        # jeu. 26 mars 22:11
        r'''find . -name fonction-lireligne.c -exec bash -c "gcc -Wall -Werror testeur-nominal-lireligne.c {} && ./a.out < testeur-nominal-lireligne.c >/dev/null && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort | grep OK'''

        # 26 mars 2026 21:49
        r'''find . -name copy.c -exec bash -c "gcc -Wall -Werror {} -o copier 2>/dev/null && ! ./copier {} >/dev/null 2>message.txt && grep -q 'nombre d.arguments incorrect' message.txt && echo {} OK || echo {} ÉCHEC" \; | grep -e ÉCHEC -e OK | sort''',

        # lun. 6 avr. 18:57
        r'''find . -name bigfich.c -exec bash -c "grep -q -e break -e continue -e printf {} && echo {} ÉCHEC || echo {} OK" \; 2>/dev/null | sort''',
        
        # lun. 6 avr. 20:43
        r'''find . -name puts.c -exec bash -c "grep -q printf {} && echo {} ÉCHEC || echo {} OK" \;''',


    ],

   ]

if __name__ == "__main__":
    execution(listCmd)
