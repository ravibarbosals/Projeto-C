# Jogo de Adivinhação - CODE RIDDLER

## 1. Membros da Equipe
- Ravi Barbosa - [@ravibarbosals](https://github.com/ravibarbosals)
- Eduardo Rocha - [@dudurrocha](https://github.com/dudurrocha) 
- Gabriel Calado - [@gcalado55](https://github.com/gcalado55) 
- Rafael Gomes - [@Rafagomess25](https://github.com/Rafagomess25)
- Pedro Gomes - [@Pedro-gomes123](https://github.com/Pedro-gomes123)

## 2. Disciplina
Programação Imperativa e Funcional - 2025.1
Lógica de Programação - 2025.1

## 3. Instituição de Ensino
CESAR School

## 4. Nome do jogo
**CODE RIDDLER**

## 5. Instruções para compilar e executar

✅ Pré-requisitos

Estar em um ambiente Linux (ou WSL com Ubuntu).

Ter o GCC e o make instalados no sistema.

Estar dentro do diretório do projeto.

Passos:

-Como instalar o GCC e Make:
 bash:
 sudo apt update
 sudo apt install build-essential

 Ou escreva esse codigo aqui que ja vai instalar tudo e preparar seu ambiente:
 **sudo apt update && sudo apt install -y build-essential**

-Acesse o diretório do projeto usando o WSL Ubuntu:

**cd /mnt/d/JOGOS\ EPIC/ravi\ vscode/Projeto**

-Compile o projeto com o Makefile:
make

Execute o jogo:
./build/game

Para limpar os arquivos compilados:
make clean

## 6. Descrição do jogo
**CODE RIDDLER** é um jogo de adivinhação por fases, onde o jogador deve decifrar um número secreto com base em enigmas por fase. A cada fase, a dificuldade aumenta, e o número de tentativas é limitado. E durante o jogo temos o personagem RIDDLER(Charada) que vai ficar desdenhando da sua cara e dizendo as charadas de forma teatral. Queremos também implementar assuntos aprendidos em Lógica para programação

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

"Divide o mundo em dois, sem resto, sem razão..."

"Nunca caminha aos pares, sempre sozinho vai.."

"Dança no ritmo das mãos... conte nos dedos e vai adivinhar..."


## 🚧 Em desenvolvimento:
Integração com a biblioteca CLI-lib para uma interface mais dinâmica no terminal.

Sistema de pontuação e tempo.

Possibilidade de reiniciar a fase.
