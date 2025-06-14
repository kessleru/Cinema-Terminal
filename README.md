# 🎬 Sistema de Cinema - Terminal

Um sistema completo de gerenciamento de cinema desenvolvido em linguagem C, com funcionalidades de reserva de assentos, controle de sessões e gestão de vendas.

## 📋 Descrição

O **Sistema de Cinema Terminal** é uma aplicação em linha de comando que simula o funcionamento de um cinema real. O sistema permite gerenciar sessões de filmes, controlar a ocupação de assentos, calcular preços diferenciados e gerar relatórios de vendas.

## ✨ Funcionalidades

- **🎭 Gestão de Sessões**: Configuração de salas e filmes
- **💺 Reserva de Assentos**: Sistema visual de seleção de lugares
- **💰 Preços Diferenciados**: Assentos normais e VIP
- **📊 Layout da Sala**: Visualização em tempo real da ocupação
- **🎫 Sistema de Vendas**: Controle completo de ingressos
- **📈 Relatórios**: Estatísticas de ocupação e vendas

## 🛠️ Tecnologias Utilizadas

- **Linguagem C**: Programação em C padrão
- **Estruturas (Structs)**: Organização dos dados do cinema
- **Matrizes 2D**: Representação dos assentos da sala
- **Interface Terminal**: Menu interativo em linha de comando
- **Manipulação de Arquivos**: Persistência de dados (opcional)

## 🎪 Estrutura da Sala

### Layout do Cinema:
```
         TELA
    1    2    3    4    5    6    7
A  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]   
B  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]   ← Assentos Normais
C  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]   
D  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]   
E  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]   

F  [VIP] [VIP] [VIP] [VIP] [VIP]       ← Assentos VIP
G  [VIP] [VIP] [VIP] [VIP] [VIP]       
H  [VIP] [VIP] [VIP] [VIP] [VIP]       
```

### Características:
- **Assentos Normais**: Fileiras A-E (5x7 = 35 lugares)
- **Assentos VIP**: Fileiras F-H (3x5 = 15 lugares)
- **Capacidade Total**: 50 assentos por sessão
- **Preços Diferenciados**: Normal e VIP

## 📁 Estrutura do Projeto

```
Cinema-Terminal/
├── cinema.c            # Código fonte principal
├── LICENSE             # Licença do projeto
├── README.md           # Documentação
└── output/             # Arquivos compilados
    └── cinema.exe      # Executável para Windows
```

## 🏗️ Estrutura de Dados

### Estrutura Sessão:
```c
struct sessao {
    char sala[50];              // Nome da sala
    char filme[50];             // Nome do filme
    int cadeirasAtras[5][7];    // Matriz assentos normais
    int cadeirasFrente[3][5];   // Matriz assentos VIP
    int capacidade;             // Capacidade total
    int disponivel;             // Assentos disponíveis
    float precoNormal;          // Preço assento normal
    float precoVIP;             // Preço assento VIP
};
```

## 🚀 Como Compilar e Executar

### No Windows:
```bash
gcc cinema.c -o output/cinema.exe
./output/cinema.exe
```

### No Linux/Mac:
```bash
gcc cinema.c -o output/cinema
./output/cinema
```

### Com flags de otimização:
```bash
gcc -Wall -Wextra -O2 cinema.c -o cinema
```

## 🎯 Menu do Sistema

```
=== SISTEMA DE CINEMA ===
1. Visualizar Layout da Sala
2. Reservar Assento
3. Cancelar Reserva
4. Relatório de Ocupação
5. Relatório de Vendas
6. Configurar Sessão
7. Sair do Sistema
```

## 💻 Funcionalidades Detalhadas

### 1. **Visualização do Layout**
- Exibe o mapa completo da sala
- Mostra assentos ocupados e disponíveis
- Diferenciação visual entre normal e VIP
- Informações de capacidade e disponibilidade

### 2. **Sistema de Reservas**
- Seleção interativa de assentos
- Validação de disponibilidade
- Cálculo automático de preços
- Confirmação de reserva

### 3. **Gestão de Preços**
- **Assentos Normais**: Preço padrão
- **Assentos VIP**: Preço premium
- **Descontos**: Possibilidade de promoções
- **Relatórios**: Controle de receita

### 4. **Controle de Ocupação**
- Status em tempo real dos assentos
- Estatísticas de ocupação por área
- Previsão de lotação
- Gestão de capacidade

## 🎨 Interface Visual

### Legenda dos Assentos:
- `[ ]` - Assento disponível
- `[X]` - Assento ocupado
- `[VIP]` - Assento VIP disponível
- `[VIP-X]` - Assento VIP ocupado

### Códigos de Cores (se suportado):
- 🟢 Verde: Assentos disponíveis
- 🔴 Vermelho: Assentos ocupados
- 🟡 Amarelo: Assentos VIP
- 🔵 Azul: Seleção atual

## 📊 Sistema de Relatórios

### Relatório de Ocupação:
```
=== RELATÓRIO DE OCUPAÇÃO ===
Sala: Cinema 1
Filme: [Nome do Filme]
Capacidade Total: 50 assentos
Ocupados: 32 assentos (64%)
Disponíveis: 18 assentos (36%)

Assentos Normais: 22/35 (63%)
Assentos VIP: 10/15 (67%)
```

### Relatório de Vendas:
```
=== RELATÓRIO DE VENDAS ===
Ingressos Normais: 22 x R$ 15,00 = R$ 330,00
Ingressos VIP: 10 x R$ 25,00 = R$ 250,00
Total Arrecadado: R$ 580,00
```

## 🔧 Funcionalidades Técnicas

- **Validação de Entrada**: Verificação de posições válidas
- **Controle de Estado**: Gerenciamento da ocupação
- **Cálculos Automáticos**: Preços e estatísticas
- **Interface Amigável**: Navegação intuitiva
- **Tratamento de Erros**: Operações seguras

## 📈 Possíveis Melhorias

- [ ] Sistema de horários múltiplos
- [ ] Diferentes tipos de ingresso (estudante, idoso)
- [ ] Integração com banco de dados
- [ ] Interface gráfica (GTK/SDL)
- [ ] Sistema de reserva online
- [ ] Histórico de sessões
- [ ] Relatórios em PDF
- [ ] Sistema de fidelidade

## 🎓 Conceitos Aprendidos

- **Matrizes 2D**: Representação de dados bidimensionais
- **Estruturas Complexas**: Organização de múltiplos dados
- **Interface de Usuario**: Criação de menus interativos
- **Lógica de Negócio**: Implementação de regras comerciais
- **Controle de Estado**: Gerenciamento de mudanças
- **Validação de Dados**: Garantia de integridade

## 📄 Licença

Este projeto está licenciado sob os termos especificados no arquivo LICENSE.

---

*Desenvolvido como projeto educacional para demonstrar programação em C e lógica de sistemas* 🎭
