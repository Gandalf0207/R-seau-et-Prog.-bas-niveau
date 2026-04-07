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
    ],

    #--------TD4---------#
    [
        # 18 févr. 2026 15:01
        r'''find . -name negative.c -exec bash -c "gcc -Wall -Werror {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # jeu. 19 févr. 11:33
        r'''find . -name intensite.c -exec bash -c "gcc -Wall -Werror {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # lun. 23 févr. 18:12
        r'''find . -name intensite.c -exec bash -c "[ -e out.ppm ] && rm -f out.ppm ; gcc -Werror {} && ./a.out test.ppm out.ppm 32 && cmp out.ppm test-plus-32.ppm && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # ven. 20 févr. 10:02
        r'''find . -name mono.c -exec bash -c "gcc -Wall -Werror {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # 25 févr. 2026 10:32
        r'''find . -name mono.c -exec bash -c "gcc -Wall -Werror {} && ./a.out test.wav out.wav && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # 23 févr. 2026 15:16
        r'''find . -name negative.c -exec bash -c "gcc -Wall -Werror {} && ./a.out test.pgm out.pgm && cmp out.pgm test-en-négatif.pgm && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # 22 févr. 2026 20:28
        r'''find . -name ascii-check.c -exec bash -c "gcc -Werror {} && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null''',

        # mer.25 févr. 14:13
        r'''find . -name ascii-check.c -exec bash -c "! grep printf {} && gcc -Werror '{}' && timeout 1 ./a.out citation-célèbre.txt | grep -q 'fichier compatible ASCII' && ./a.out ./a.out | grep -q 'fichier incompatible ASCII' && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # lun. 2 mars 18:40
        r'''find . -name negative.c -exec bash -c "gcc -Wall -Werror {} && ./a.out test.pgm out.pgm && cmp out.pgm test-en-négatif.pgm && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort | grep OK''',

        # dim. 8 mars 09:50
        r'''find . -name intensite.c -exec bash -c "[ -e out.ppm ] && rm -f out.ppm ; gcc -Werror {} && ./a.out test.ppm out.ppm 32 && cmp out.ppm test-plus-32.ppm && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort | grep OK''',

        # ven. 13 mars 09:14
        r'''find . -name mono.c -exec bash -c "rm -f out.wav ; gcc {} && ./a.out test.wav out.wav && cmp out.wav test-en-mono.wav 1>/dev/null 2>/dev/null && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # ven. 13 mars 09:14
        r'''find . -name mono.c -exec bash -c "rm -f out.wav && gcc {} && ./a.out test.wav out.wav && cmp -n 44 out.wav test-en-mono.wav >/dev/null && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort | grep OK''',

        # ven. 13 mars 21:19
        r'''find . -name ascii-check.c -exec bash -c "! grep printf {} && gcc -Werror '{}' && timeout 1 ./a.out citation-célèbre.txt | grep -q 'fichier compatible ASCII' && ./a.out ./a.out | grep -q 'fichier incompatible ASCII' && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort | grep OK''',

        # jeu. 19 mars 20:19
        r'''find . -name negative.c -exec bash -c "grep -q -e scanf -e printf {} && echo {} ÉCHEC" \; | sort''',

        # ven. 20 mars 10:28
        r'''echo -e "nombre d'arguments incorrect" > ref.txt && find . -name intensite.c -exec bash -c "gcc -Werror {} && ./a.out 1>/dev/null 2>err.txt && echo {} ÉCHEC || (cmp -s ref.txt err.txt && echo {} OK || echo {} ÉCHEC)" \; | sort''',

        # ven. 20 mars 10:42
        r'''find . -name mono.c -exec bash -c "rm -f out.wav && gcc {} && ./a.out test.wav out.wav && cmp -n 44 out.wav test-en-mono.wav >/dev/null && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort | grep OK''',
        r'''find . -name mono.c -exec bash -c "rm -f out.wav ; gcc {} && ./a.out test.wav out.wav && cmp out.wav test-en-mono.wav 1>/dev/null 2>/dev/null && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort | grep OK''',

        # 26 mars 2026 22:27
        r'''find . -name ascii-check.c -exec bash -c "grep -qe break {} && echo {} ÉCHEC || echo {} OK" \; | sort''',

        # dim. 5 avr. 19:06
        r'''find . -name negative.c -exec bash -c "! grep -e printf -e scanf {} && gcc -Wall -Werror {} && ./a.out test.pgm out.pgm && cmp out.pgm test-en-négatif.pgm && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort | grep OK''',


    ],
   ]

if __name__ == "__main__":
    execution(listCmd)
