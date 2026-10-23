# AurixTC375
AurixTC375  Support https://github.com/Annabel369/Infineon

# [BR] Infineon AURIX TriCore & ESP32 Boards for Arduino
# Infineon AURIX TriCore & ESP32 Boards for Arduino

Support for boards based on the **Infineon AURIX™ TriCore™** architecture (such as the **ShieldBuddy TC375**) and **ESP32** devices in the Arduino IDE, tailored for secure hardware projects and password vaults.

---

## [BR] Instalação via Gerenciador de Placas (Boards Manager)
## Installation via Boards Manager

1. Open the **Arduino IDE**.
2. Go to **File > Preferences** (or **Arquivo > Preferências**).
3. In the **Additional Boards Manager URLs** field, add:
   ```text
   [https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json](https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json), [https://raw.githubusercontent.com/Annabel369/Infineon/main/package.json](https://raw.githubusercontent.com/Annabel369/Infineon/main/package.json)

<img width="912" height="1166" alt="Gemini_Generated_Image_w6eeflw6eeflw6ee" src="https://github.com/user-attachments/assets/728d8465-d396-40c6-bddb-e776fdff88d9" />



<img width="1292" height="784" alt="image" src="https://github.com/user-attachments/assets/964e09b0-6066-4bed-a7d8-a4886ed571a3" />


https://drive.google.com/file/d/1ECEsE9SIlTl64vtcYlzWbm0sV1c-1IhS/view

<img width="1669" height="812" alt="image" src="https://github.com/user-attachments/assets/1d1692ca-3fad-4ee6-983d-638a090c5a55" />

<img width="1736" height="679" alt="image" src="https://github.com/user-attachments/assets/69e1b6da-35ff-4686-8f56-b018e03e2a40" />

Mapeamento de Pinos Completo na ShieldBuddy TC375:


#Periférico                   Pino do Módulo             Pino na ShieldBuddy TC375           Função

    MicroSD	                 CS                         Pin 10	                            Seleção do Cartão SD  
    OLED 1.27"               CS	                        Pin 9	                              Seleção da Tela OLED
    OLED 1.27"	             DC	                        Pin 8	                              Dados / Comando (Data/Command)
    OLED 1.27"	             RES	                      Pin 7	                              Reset do Display
    SPI Compartilhado	       SCK / CLK	                Pin 13	                            Clock SPI
    SPI Compartilhado	       MOSI / DIN	                Pin 11	                            Dados SPI (Master Out Slave In)
    SPI Compartilhado	       MISO / SO	                Pin 12	                            Dados SPI (Master In Slave Out - Usado só pelo SD)


<img width="417" height="665" alt="image" src="https://github.com/user-attachments/assets/7fdc30ab-3cec-449d-862b-81c473a2be95" />




