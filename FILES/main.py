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
        # jeu. 22 janv. 21:45
        r'''find . -name simple.c -exec bash -c "gcc -Werror {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # ven. 23 janv. 12:12
        r'''find . -name main-et-dbl.c -exec bash -c "gcc -Werror {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # lun. 26 janv. 09:36
        r'''find . -name main-cent-premiers.c -exec bash -c "gcc -Werror {} && echo {} OK || echo {} ÉCHEC" \;''',

        # lun. 26 janv. 09:40
        r'''find . -name main-ni-par-3-ni-par-7.c -exec bash -c "gcc -Werror {} && echo {} OK || echo {} ÉCHEC" \;''',

        # lun. 26 janv. 11:48
        r'''find . -name lngcha.c -exec bash -c "gcc -c -Werror {} && echo {} OK || echo {} ÉCHEC" \;''',

        # lun. 26 janv. 12:31
        r'''find . -name palindrome.c -exec bash -c "gcc -c -Werror {} && echo {} OK || echo {} ÉCHEC" \;''',

        # lun. 26 janv. 14:22
        r'''find . -name age_total.c -exec bash -c "gcc -c {} -I. && echo {} OK || echo {} ÉCHEC" \;''',

        # lun. 26 janv. 14:38
        r'''find . -name simple.c -exec bash -c "gcc -Werror {} && ./a.out >out.txt && grep -q 'Youpi \!$' out.txt && grep -q 'Super' out.txt && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # mer. 28 janv. 22:30
        r'''find . -name main-et-dbl.c -exec bash -c "gcc -Werror {} && (./a.out | grep -q 'résultat: 8' && echo {} OK || echo {} ÉCHEC) || echo {} ERREUR COMPIL." \; 2>/dev/null | sort''',

        #   mer. 28 janv. 22:53
        r'''find . -name main-cent-premiers.c -exec bash -c "gcc -Werror {} && (./a.out | grep -e '^1 2 3 4 5' | grep -q '96 97 98 99 100[ ]$' && echo {} OK || echo {} ÉCHEC) || echo {} ÉCHEC COMPIL." \; 2>/dev/null | sort''',

        # jeu. 29 janv. 13:26
        r'''find . -name main-ni-par-3-ni-par-7.c -exec bash -c "gcc -Werror {} && ./a.out | tr '\n' ' ' | grep -q '1 2 4 5 8 10 11 13 16 17 19 20 22.*88 89 92 94 95 97 100' && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # sam. 31 janv. 09:20
        r'''find . -name lngcha.c -exec bash -c "gcc testeur-nominal-lngcha.c {} && ( ./a.out && echo {} OK || echo {} ÉCHEC ) || echo {} ERREUR COMPIL." \; 2>/dev/null | sort''',

        # dim. 1 févr. 22:06
        r'''find . -name palindrome.c -exec bash -c "gcc testeur-nominal-palindrome.c {} && (./a.out >/dev/null && echo {} OK || echo {} ÉCHEC) || echo {} ERREUR COMPIL." \; 2>/dev/null | sort''',

        # lun. 2 févr. 12:16
        r'''find . -name age_total.c -exec bash -c "gcc testeur-nominal-age-total.c {} && ./a.out >/dev/null && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # mar. 3 févr. 19:53
        r'''find . -name simple.c -exec bash -c "gcc -Werror {} && ./a.out >out.txt && grep -q 'Youpi \!$' out.txt && grep -q 'Super' out.txt && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort | grep OK''',

        # ven. 6 févr. 09:36
        r'''find . -name main-et-dbl.c -exec bash -c "gcc -Werror {} && (./a.out | grep -q 'résultat: 8' && echo {} OK || echo {} ÉCHEC) || echo {} ERREUR COMPIL." \; 2>/dev/null | sort | grep OK''',

        # mer. 11 févr. 22:51
        r'''find . -name main-cent-premiers.c -exec bash -c "clang-format --style=LLVM --dry-run -Werror {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # jeu. 12 févr. 10:28
        r'''find . -name main-ni-par-3-ni-par-7.c -exec bash -c "grep -q -e ' & ' -e 'continue' {} && echo {} ÉCHEC || echo {} OK" \; | sort''',

        # mer. 18 févr. 19:23
        r'''find . -name palindrome.c -exec bash -c "clang-format {} > out.c && ! grep -q 'for (' out.c && ! grep break out.c && [ \$(grep -c 'return' out.c) -eq 1 ] && echo {} OK || echo {} ÉCHEC" \; | sort''',

    ],


    #--------TD2---------#
    [
        # mer. 28 janv. 22:47
        r'''find . -name maximum.c -exec bash -c "gcc -c -Werror {} && echo {} OK || echo {} ÉCHEC" \; | sort''',

        # jeu. 29 janv. 13:14
        r'''find . -name maximum.h -exec bash -c "gcc -fsyntax-only {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # jeu. 29 janv. 20:29
        r'''find . -name minmax.c -exec bash -c "gcc -c -Werror {} && echo {} OK || echo ÉCHEC COMPIL." \; | sort''',

        # dim. 1 févr. 21:35
        r'''find . -name minmax.h -exec bash -c "gcc -Wall -Werror -fsyntax-only {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # lun. 1 févr. 08:49
        r'''find . -name nvtab.c -exec bash -c "gcc -Werror -c {} && echo {} OK || echo {} ÉCHEC COMPIL." \;''',

        # lun. 1 févr. 19:32
        r'''find . -name unsurdeux.c -exec bash -c "gcc -c -Werror {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # mar. 3 févr. 2026 20:54
        r'''find . -name matrice.h -exec bash -c "gcc -Werror -fsyntax-only {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # mar. 3 févr. 21:00
        r'''find . -name matrice.c -exec bash -c "gcc -Werror -c {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # mar. 3 févr. 21:39
        r'''find . -name maximum.c -exec bash -c "gcc testeur-nominal-maximum.c {} && (./a.out && echo {} OK || echo {} ÉCHEC) || echo {} ERREUR COMPIL." \; 2>/dev/null | sort''',

        # mer. 4 févr. 19:17
        r'''find . -name maximum.h -exec bash -c "gcc -include {} -Werror -c testeur-header-maximum.c && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # ven. 6 févr. 20:29
        r'''find . -name minmax.c -exec bash -c "gcc testeur-nominal-minmax.c {} && (./a.out && echo {} OK || echo {} ÉCHEC) || echo {} ÉCHEC COMPIL." \; 2>/dev/null | sort''',

        # dim. 8 févr. 07:56
        r'''find . -name minmax.h -exec bash -c "gcc -Wall -Werror -c testeur-header-minmax.c -include {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # lun. 9 févr. 10:25
        r'''find . -name nvtab.c -exec bash -c "gcc testeur-nominal-nvtab.c {} && (./a.out && echo {} OK || echo {} ÉCHEC) || echo {} ÉCHEC COMPIL" \; 2>/dev/null | sort''',

        # lun. 9 févr. 11:01
        r'''find . -name unsurdeux.c -exec bash -c "gcc -Werror testeur-nominal-unsurdeux.c {} && (./a.out && echo {} OK || echo {} ÉCHEC) || echo {} ERREUR COMPIL." \; 2>/dev/null | sort''',

        # lun. 9 févr. 11:49
        r'''find . -name matrice.h -exec bash -c "gcc -c --include {} testeur-header-matrice.c && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # lun. 9 févr. 15:23
        r'''find . -name matrice.c -exec bash -c "gcc testeur-nominal-affiche-matrice.c {} && ./a.out > out.txt && grep -Eq '^ *1 +2 +3 *$' out.txt && grep -Eq '^ *4 +5 +6 *$' out.txt && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # jeu. 12 févr. 07:38
        r'''find . -name maximum.c -exec bash -c "gcc testeur-nominal-maximum.c {} && (./a.out && echo {} OK || echo {} ÉCHEC) || echo {} ERREUR COMPIL." \; 2>/dev/null | sort | grep OK''',

        # sam. 14 févr. 16:24
        r'''find . -name maximum.h -exec bash -c "gcc -include {} -Werror -c testeur-header-maximum.c && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # dim. 15 févr. 08:18
        r'''find . -name lngcha.c -exec bash -c "gcc testeur-nominal-lngcha.c {} && ( ./a.out && echo {} OK || echo {} ÉCHEC ) || echo {} ERREUR COMPIL." \; 2>/dev/null | sort | grep OK''',

        #   dim. 15 févr. 08:51
        r'''find . -name minmax.c -exec bash -c "gcc testeur-limite-minmax.c {} && (./a.out && echo {} OK || echo {} ERREUR) || echo {} ERREUR COMPIL." \; 2>/dev/null | sort''',

        # lun. 16 févr. 14:03
        r'''find . -name minmax.h -exec bash -c "grep -q -e 'minmax.*\[\]' {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # lun. 16 févr. 15:36
        r'''find . -name minmax.h -exec bash -c "grep 'minmax' {} | grep -qHF '[]' && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # 18 févr. 2026 14:49
        r'''find . -name nvtab.c -exec bash -c "gcc testeur-nominal-nvtab.c {} && (./a.out && echo {} OK || echo {} ÉCHEC) || echo {} ÉCHEC COMPIL" \; 2>/dev/null | sort | grep OK''',
    ],

    #--------TD3---------#

    [


    ],
   ]

if __name__ == "__main__":
    execution(listCmd)
