# Jogo de Adivinhação - CODE RIDDLER

## 1. Membros da Equipe
- Ravi Barbosa - [@ravibarbosals](https://github.com/ravibarbosals)
- Eduardo Rocha - [@dudurrocha](https://github.com/dudurrocha) 
- Gabriel Calado - [@gcalado55](https://github.com/gcalado55) 
- Rafael Gomes - [@Rafagomess25](https://github.com/Rafagomess25)
- Pedro Gomes - [@Pedro-gomes123](https://github.com/Pedro-gomes123)

## 2. Disciplina
Programação Imperativa e Funcional - 2025.1

## 3. Instituição de Ensino
CESAR School

## 4. Nome do jogo
**CODE RIDDLER**

## 5. Instruções para compilar e executar

✅ Pré-requisitos
Compilador C instalado (ex: GCC via MinGW no Windows)

A biblioteca CLI-lib colocada corretamente:

Arquivos .h da biblioteca devem estar em include/

Arquivos .c da biblioteca devem estar em src/

🛠️ Compilação
No terminal, dentro da raiz do projeto, execute:

**gcc ./src/*.c -I./include -o coderiddler**

Isso compila todos os arquivos .c da pasta src/ e usa os cabeçalhos da pasta include/.
O executável coderiddler será gerado na raiz do projeto.

▶️ Execução
No terminal (após compilar), rode:

**./coderiddler**

No Windows, você pode executar com:

**coderiddler.exe**

## 6. Descrição do jogo
**CODE RIDDLER** é um jogo de adivinhação por fases, onde o jogador deve decifrar um número secreto com base em enigmas por fase. A cada fase, a dificuldade aumenta, e o número de tentativas é limitado. E durante o jogo temos o personagem RIDDLER(Charada) que vai ficar desdenhando da sua cara e dizendo as charadas de forma teatral.

## 🎮 Regras do Jogo:
O jogo possui 3 fases, com níveis de dificuldade crescentes.

Em cada fase, um número é gerado aleatoriamente:

Fase 1: entre 1 e 100

Fase 2: entre 1 e 500

Fase 3: entre 1 e 1000

O jogador recebe enigmas como pista.

A partir dos enigmas, ele tem 7 tentativas para adivinhar o número.

Na Fase 3, se o jogador errar 7 vezes, o número secreto muda automaticamente.


## 🧠 Exemplos de Enigmas:
Os enigmas ainda estão sendo pensados, pois estamos pensando em usar assuntos da materia de lógica para programação, mas se não formos implementar essa ideia o padrão dos enigmas seriam esses:

"Divide o mundo em dois, sem resto, sem razao..."

"Nunca caminha aos pares, sempre sozinho vai.."

"Dança no ritmo das mãos... conte nos dedos e vai adivinhar..."


## 🚧 Em desenvolvimento:
Integração com a biblioteca CLI-lib para uma interface mais dinâmica no terminal.

Sistema de pontuação e tempo.

Possibilidade de reiniciar a fase.