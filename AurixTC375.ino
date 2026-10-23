#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>

// Definições da Tela OLED RGB de 1.27" (128x96 pixels)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 96

// Pinos de controle da Tela OLED (SPI por Hardware)
#define OLED_CS    9
#define OLED_DC    8
#define OLED_RES   7

// Pino de seleção do Cartão MicroSD
const int sdChipSelect = 10;

// Inicializa o objeto da tela OLED SSD1351
Adafruit_SSD1351 oled = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_CS, OLED_DC, OLED_RES);

// Definição de algumas cores básicas em formato 16-bit (RGB565)
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(115200);
  while (!Serial) {
    ; // Aguarda a serial conectar
  }

  Serial.println("\n--- Iniciando Projeto: TriCore Aurix Vault & Gerenciador de Senhas ---");

  // 1. Inicializa a Tela OLED
  oled.begin();
  oled.fillScreen(BLACK);
  oled.setCursor(0, 10);
  oled.setTextColor(GREEN);
  oled.setTextSize(1);
  oled.println("[BR] AURIX TC375");
  oled.println("Gerenciador de Senhas");
  delay(1500);

  // 2. Inicializa o Cartão MicroSD
  oled.fillScreen(BLACK);
  oled.setCursor(0, 10);
  oled.setTextColor(WHITE);
  oled.print("Iniciando SD...");
  
  if (!SD.begin(sdChipSelect)) {
    Serial.println("Erro: Falha ao inicializar o cartao MicroSD!");
    oled.setCursor(0, 30);
    oled.setTextColor(RED);
    oled.print("Erro SD!");
    return;
  }
  
  Serial.println("Cartao MicroSD inicializado com sucesso!");
  oled.setCursor(0, 30);
  oled.setTextColor(GREEN);
  oled.print("SD OK!");
  delay(1000);

  // 3. Grava dados de exemplo (Gerenciador de Senhas / Carteira Diário)
  File meuarquivo = SD.open("vault.txt", FILE_WRITE);
  if (meuarquivo) {
    meuarquivo.println("=== TRI-CORE ARIX XX VAULT ===");
    meuarquivo.println("Chave Mestra: Ativada com Seguranca");
    meuarquivo.close();
    Serial.println("Dados salvos no cofre do SD.");
  }

  // Tela Inicial Pronta no OLED
  oled.fillScreen(BLACK);
  oled.setCursor(0, 10);
  oled.setTextColor(CYAN);
  oled.print("=== COFRE SEGURO ===");
  oled.setCursor(0, 30);
  oled.setTextColor(WHITE);
  oled.print("Sistema pronto!");
  oled.setCursor(0, 50);
  oled.setTextColor(YELLOW);
  oled.print("Aguardando senha...");
}

void loop() {
  // Aqui você pode implementar a lógica do seu gerenciador de senhas,
  // leitura de botões, matriz de teclado ou comandos via serial.
}
