# ReadMe

### Ribosome

Ribosome is a prototype built on Godot engine intended as a segment of a larger interactive educational experience. Which is designed to tackle the central dogma of molecular biology using different interactive tools, games and simulations.

Ribosome revolves around cell translation, meaning decoding RNA to amino acids chains. It is developed for children to learn and explore in a playful way the cell translation process on a molecular level, where a sequence of ARN needs to be typed for the game to start. The Input to build the sequence can only be A/C/G/U , letters that represent the RNA nucleotides (letters other than those will make the prototype crash). Once the input  is loaded the player needs to move the ribosome, pick up the ARN sequence and start collecting the right amino acids that match the ARN codons. If the wrong amino acid is picked, it will get stuck in the ribosome for a short while, making the player lose time. The game is scored by a timer.

The game intends to teach in two different levels. By just playing it, one will be guided through the translation mechanisms and on how decoding biological sequences works. However, one can also learn how to code some of the game dynamics by accessing the source code. This will provide insights of basic programming skills, such as building dictionaries for decoding the  ARN codons, or exploring the physics of moving objects using vectors, interacting with list iterations, or being able to read and make sense out of someone else's code. That's one of the reasons why we used Godot, an open source engine that employs GDscript as a programming language which is built from Python and will surely make a much more friendly learning experience than other languages.

So far the dynamic of the game and the physics has been coded but the biological decoding
still needs to be done, so for the time being, the matching from codons to amino acids is just by colors. Nevertheless, the prototype still gives a  fair good idea of how the game will work.

As mentioned before Ribosome is a segment of a larger interactive educational experience composed of other three segments. Each segment explores a mechanism which is key for all cell functions: DNA replication, transcription, translation and protein folding to native structure. After being introduced to these processes, learners are intended to solve puzzles or interactive games that will provide further insights and understanding of the topics with a hand-on approach.

For example, for the transcription segment a puzzle may be presented where transcription factors and other molecules will need to be properly assembled in the DNA recognition segments (such as TATA-box, etc.) of a given gene for transcription to begin. We aim in this way to create a proper environment for students to incorporate such concepts while always keeping in mind that fun is a key tool  to improve learning and focus.

Regarding DNA replication, the goal could be to aid the DNA polymerase in replication by typing the corresponding nucleotides as fast as possible; this could be used to introduce concepts such as miss matches, mutations, accuracy rate, SNPs, mutation rate, etc.

A way to introduce protein structure, may be a game with a similar display as “Guitar Hero” where,  while helping proteins to “move and dance to a given song” one can guide them through their folding journey until they get to their native structure, showing mainly the display of three dimensional proteins, the two stage models of protein folding, protein folding simulations, AlphaFold and crystallize proteins.

In this way, throughout the whole learning experience one can explore different genes and follow the paths along the cell until getting to the protein's native structure and relate them with their function.

