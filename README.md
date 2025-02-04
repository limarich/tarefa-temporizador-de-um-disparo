# Tarefa: Temporizador de um Disparo (One Shot)

## Descrição
Este projeto implementa um **temporizador de um disparo (One Shot)** utilizando o **Pico SDK** e o microcontrolador **Raspberry Pi Pico W**. O sistema liga três LEDs ao pressionar um botão e os desliga um a um a cada **3 segundos**.

A implementação é feita na **linguagem C**, para execução no microcontrolador **Raspberry Pi Pico W** e pode ser simulada utilizando o **Wokwi** ou **BitDogLab**.

---

## 📋 Requisitos da Atividade

1. **Botão inicia o ciclo**: Ao pressionar o botão, os três LEDs são ligados simultaneamente.
2. **Desligamento sequencial**: Os LEDs são desligados um a um, com intervalo de **3 segundos** entre cada estado.
3. **Uso da função `alarm_callback()`** para realizar o desligamento progressivo.
4. **Debounce do botão**: Implementado para evitar acionamentos errôneos.
5. **Botão só pode ser pressionado novamente após o ciclo de desligamento** estar concluído.
6. **Simulação recomendada com BitDogLab** e execução no VS Code.

---

## 🔧 Configuração do Hardware

### 📌 Componentes Necessários:
- 1 x **Raspberry Pi Pico W**
- 3 x **LEDs** (Vermelho, Azul e Verde)
- 3 x **Resistores de 330 Ω**
- 1 x **Botão (Pushbutton)**
- Jumpers para conexão
- Placa de ensaio (opcional)

### 📌 Ligação dos LEDs e Botão:

| Componente  | GPIO |
|------------|------|
| LED Vermelho   | 13   |
| LED Azul       | 12   |
| LED Verde      | 11   |
| Botão         | 5    |

---

## 📜 Estrutura do Código

## 🖥️ Configuração do Ambiente de Desenvolvimento

### 📌 Ferramentas:
- **VS Code** (com extensão C/C++)
- **Pico SDK** (instalado e configurado)
- **CMake e Make**
- **Simulador Wokwi ou BitDogLab**

### 📌 Clonando o Repositório e Compilando:
```sh
# Clonar o repositório
git clone https://github.com/limarich/tarefa-temporizador-de-um-disparo.git
cd tarefa-temporizador

utilizar a biblioteca Raspberry Pico W para compilar o projeto
```


### 📌 Fluxograma da Lógica do Temporizador de um Disparo:
```text
[INÍCIO]
   |
   V
[Botão pressionado: Liga todos os LEDs]
   |
   V
(Espera 3s)
   |
   V
[Desliga LED Azul]
   |
   V
(Espera 3s)
   |
   V
[Desliga LED Vermelho]
   |
   V
(Espera 3s)
   |
   V
[Desliga LED Verde]
   |
   V
[Reinicia ciclo: Botão pode ser pressionado novamente]
```

---
