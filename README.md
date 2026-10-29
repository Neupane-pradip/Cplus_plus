# C++ Programming Exercises

My Programming 2: Structures coursework repository from Tampere University, spring 2024.

The repository brings together independent C++ exercises, course examples, and starter templates. Console programs and Qt graphical applications are built separately.

## Find the code

| Folder | Contents |
|---|---|
| [student](student/) | Student exercise work |
| [examples](examples/) | Examples supplied by course staff |
| [templates](templates/) | Starter code supplied by course staff |

Examples of exercise projects include:

- [Console Binairo](student/04/binairo/): a puzzle exercise with a separate game-board class.
- [Simple library](student/03/simple_library/): book and date classes.
- [Student register](student/08/student_register/): file-based register exercise.
- [Hospital](student/10/hospital/): a multi-file project with care-period, patient, and date classes.
- [Graphical Binairo](student/12/binairo/): a later Qt project.

These are course exercises at different stages; no repository-wide completion or test-pass claim is made.

## Build and run

Install a C++ toolchain and Qt Creator with a compatible Qt/qmake kit. Open the selected exercise's `.pro` file in Qt Creator, configure its kit, then build and run that project.

For example, open:

```text
student/04/binairo/binairo.pro
```

This console exercise requests C++11 and disables Qt linkage. Other projects have their own settings and may require Qt Widgets.

For command-line builds, run qmake against the chosen `.pro` file in a separate build directory, then use the kit's build tool, such as `make`, `mingw32-make`, or `nmake`.

## Working with the exercises

Each folder is an independent program. Check its source and any provided instructions for input formats and required data files. There is no single root build or unified automated test command.

Course examples and templates are supplied material, not a claim of original authorship. Keep their attribution when reusing them.

<details>
<summary>Original bilingual course instructions</summary>

Ohjelmointi 2: Rakenteet, kevät 2024

Kurssin oppimateriaali: https://plus.tuni.fi/comp.cs.110/spring-2024/

Tämä Git-repositorio sisältää kolme hakemistoa (kansiota):
- examples: henkilökunnan jakamat esimerkkikoodit
- student: opiskelijan kirjoittamat koodit
- templates: henkilökunnan jakamat koodipohjat.

ÄLÄ TEE MITÄÄN MUUTOKSIA examples- TAI templates-HAKEMISTOIHIN!

ÄLÄ KOSKAAN TEE MITÄÄN MUUTOKSIA WEB-SELAIMEN KAUTTA, VAAN KÄYTÄ
AINA KOMENTOJA git add, git commit, git push!
(Nämä komennot opit kurssin oppimistapahtumissa ja/tai
Plussa-materiaaleista.)

---------------------------------------------------------------

Programming 2: Structures, spring 2024

Study material: https://plus.tuni.fi/comp.cs.110/spring-2024/

This Git repository contains three directories (folders):
- examples: example codes given by course staff
- student: codes written by a student
- templates: code templates given by course staff.

DO NOT MAKE ANY MODIFICATIONS IN examples OR templates DIRECTORIES!

DO NOT EVER MAKE ANY MODIFICATIONS VIA THE WEB BROWSER, BUT ALWAYS
USE THE COMMANDS git add, git commit, git push!
(You will learn these commands in the learning events and/or from
the Plussa material.)

</details>
