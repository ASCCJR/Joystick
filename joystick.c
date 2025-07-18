/**
 * @file joystick.c
 * @brief Implementação do driver para o joystick analógico KY-023.
 * Inclui funções para inicializar e ler o estado dos eixos X/Y e do botão SW.
 */

/**
 * https://github.com/ASCCJR
 */

#include "joystick.h"
#include "hardware/gpio.h" // Para controle de GPIO
#include "hardware/adc.h"  // Para controle do ADC
#include "configura_geral.h" // Para JOYSTICK_X_PIN, JOYSTICK_Y_PIN, JOYSTICK_SW_PIN

// --- Implementação das Funções Públicas ---

/**
 * @brief Inicializa os pinos de GPIO e ADC para o joystick.
 * Configura os pinos dos eixos X e Y como entradas analógicas e o pino do botão SW
 * como entrada digital com pull-up.
 */
void joystick_init() {
    adc_init(); // Inicializa o hardware do ADC globalmente

    // Configura os pinos dos eixos X e Y como entradas analógicas para o ADC
    adc_gpio_init(JOYSTICK_X_PIN);
    adc_gpio_init(JOYSTICK_Y_PIN);

    // Configura o pino do botão SW como entrada digital com resistor de pull-up interno.
    // O pull-up garante que o pino esteja em nível ALTO quando o botão não está pressionado.
    // Quando pressionado, o botão conecta o pino ao GND, puxando-o para LOW.
    gpio_init(JOYSTICK_SW_PIN);
    gpio_set_dir(JOYSTICK_SW_PIN, GPIO_IN);
    gpio_pull_up(JOYSTICK_SW_PIN);
}

/**
 * @brief Lê o estado atual dos eixos X e Y do joystick e do seu botão.
 * Os valores dos eixos são de 0 a 4095. O estado do botão é true se pressionado.
 * @param state Ponteiro para uma estrutura joystick_state_t onde o estado será armazenado.
 */
void joystick_read(joystick_state_t *state) {
    // Lê o eixo X. Por padrão, o ADC está configurado para ler o pino GP26 (ADC0).
    // O seu HDB diz VRx é GP27 e VRy é GP26. Isso significa que GP26 é ADC0 e GP27 é ADC1.
    // Então, para o eixo Y (VRy) que é GP26, selecione ADC0.
    // E para o eixo X (VRx) que é GP27, selecione ADC1.
    adc_select_input(1); // Seleciona o ADC canal 1 (GP27 para eixo X)
    state->x = adc_read();

    adc_select_input(0); // Seleciona o ADC canal 0 (GP26 para eixo Y)
    state->y = adc_read();

    // Lê o estado do botão SW. A lógica é invertida (!gpio_get) porque
    // o botão puxa o pino para LOW (0) quando pressionado.
    state->sw_pressionado = !gpio_get(JOYSTICK_SW_PIN);
}
