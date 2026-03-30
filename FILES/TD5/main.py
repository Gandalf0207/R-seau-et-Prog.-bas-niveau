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
    ],

    #--------TD5---------#

    [
        # jeu. 26 févr. 14:39
        r'''find . -name ex1fork.c -exec bash -c "tr -d '\n' <{} | grep -q 'else.*sleep' && gcc {} && echo {} OK || echo {} ÉCHEC" \; | sort''',

        # jeu. 26 févr. 21:14
        r'''find . -name ex1tab.c -exec bash -c "grep -Hq WEXITSTATUS {} && echo {} OK || echo {} ÉCHEC" \; | sort''',

        # ven. 27 févr. 10:13
        r'''find . -name negative.c -exec bash -c "grep -q fork {} && gcc -Werror {} && echo {} OK" \; | sort''',

        # 27 févr. 2026 10:13
        r'''find . -name negative.c -exec bash -c "grep -e 'le père' {} && grep -e 'le fils' {}" \;''',

        # dim. 8 mars 21:05
        r'''find . -name ex2psl.c -exec bash -c "grep -q execlp {} && gcc -Werror {} 2>/dev/null && ./a.out | grep -q find && echo {} OK || echo {} ÉCHEC" \; | sort''',

        # lun. 2 mars 18:46
        r'''find . -name ex2lancer.c -exec bash -c "gcc -Werror {} && ./a.out echo Something In The Way | grep -q 'Something In The Way' && echo {} OK || echo {} ÉCHEC" \; | sort''',

        # lun. 9 mars 10:13
        r'''find . -name ex3tube.c -exec bash -c "gcc -Werror {} 2>/dev/null && ./a.out ls -R --pipe grep ex3tube.c | grep -q ex3tube.c && echo {} OK|| echo {} ÉCHEC" \; | sort''',

        # lun. 9 mars 20:06
        r'''find . -name ex1fork.c -exec bash -c "tr -d '\n' <{} | grep -q 'else.*sleep' && gcc {} && echo {} OK || echo {} ÉCHEC" \; | sort | grep OK''',

        # lun. 9 mars 11:10
        r'''find . -name ex3redirections.c -exec bash -c "gcc -Werror {} && ./a.out /usr/bin/date | grep -q 2025 && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # ven. 13 mars 13:11
        r'''find . -name ex3redirections.c -exec bash -c "gcc -Werror {} && ./a.out /usr/bin/date | grep -q 2026 && echo {} OK || echo {} ÉCHEC" \; 2>/dev/null | sort''',

        # sam. 14 mars 22:15
        r'''find . -name negative.c -exec bash -c 'rm -f out.pgm ; grep -q fork {} && gcc -Werror {} && ./a.out test.pgm out.pgm && ! cmp -s out.pgm test-en-negatif.pgm && ! cmp -s out.pgm test-en-négatif.pgm && cmp -n 16 out.pgm test.pgm && echo {} OK || echo {} ÉCHEC' \; | sort''',

        # lun. 16 mars 21:38
        r'''find . -name ex2lancer.c -exec bash -c "gcc -Werror {} && ./a.out echo Something In The Way | grep -q 'Something In The Way' && echo {} OK || echo {} ÉCHEC" \; | sort | grep OK''',

        # ven. 20 mars 12:32
        r'''find . -name ex2psl.c -exec bash -c "grep -q execlp {} && gcc -Werror {} 2>/dev/null && ./a.out | grep -q find && echo {} OK || echo {} ÉCHEC" \; | sort | grep OK''',

        # dim. 29 mars 21:51
        r'''find . -name ex3tube.c -exec bash -c "gcc -Werror {} 2>/dev/null && ./a.out ls -R --pipe grep ex3tube.c | grep -q ex3tube.c && echo {} OK|| echo {} ÉCHEC" \; | sort | grep OK''',
    ],
   ]

if __name__ == "__main__":
    execution(listCmd)
