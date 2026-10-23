#include <SPI.h>
#include <SD.h>

// Pino de seleção do cartão SD (Chip Select)
const int chipSelect = 10;

void setup() {
  // Inicializa a comunicação serial para monitoramento
  Serial.begin(115200);
  while (!Serial) {
    ; // Aguarda a porta serial conectar (se necessário)
  }

  Serial.println("\n--- Teste do Modulo MicroSD na ShieldBuddy TC375 ---");

  // Inicializa o cartão SD
  if (!SD.begin(chipSelect)) {
    Serial.println("Erro: Falha ao inicializar o cartao MicroSD!");
    Serial.println("Verifique a alimentacao (3.3V) e as conexoes dos pinos SPI (10, 11, 12, 13).");
    return;
  }
  Serial.println("Cartao MicroSD detectado e inicializado com sucesso!");

  // 1. Criar e escrever em um arquivo de texto
  File meuarquivo = SD.open("teste.txt", FILE_WRITE);

  if (meuarquivo) {
    Serial.println("Escrevendo dados no arquivo 'teste.txt'...");
    meuarquivo.println("Infineon AURIX TC375 - ShieldBuddy");
    meuarquivo.println("Gravação de dados em arquivo via protocolo SPI efetuada com sucesso!");
    meuarquivo.close(); // Fecha o arquivo para salvar os dados
    Serial.println("Dados salvos com sucesso.");
  } else {
    Serial.println("Erro ao tentar abrir o arquivo 'teste.txt' para escrita.");
  }

  // 2. Ler o conteúdo gravado no arquivo
  Serial.println("\n--- Lendo o conteudo do arquivo 'teste.txt' ---");
  meuarquivo = SD.open("teste.txt");

  if (meuarquivo) {
    while (meuarquivo.available()) {
      Serial.write(meuarquivo.read());
    }
    meuarquivo.close();
    Serial.println("\n--- Fim da leitura ---");
  } else {
    Serial.println("Erro ao abrir o arquivo para leitura.");
  }
}

void loop() {
  // O teste executa uma única vez no setup.
}
