/**
 * @file joystick.h
 * @brief Arquivo de cabeçalho para o driver do joystick analógico KY-023.
 * Declara a API pública para inicializar e ler o estado do joystick (eixos X/Y e botão).
 */

/**
 * https://github.com/ASCCJR
 */

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "pico/stdlib.h" // Para tipos básicos como uint16_t, bool

/**
 * @struct joystick_state_t
 * @brief Estrutura para armazenar o estado completo do joystick.
 */
typedef struct {
    uint16_t x;          ///< Valor do eixo X (0-4095).
    uint16_t y;          ///< Valor do eixo Y (0-4095).
    bool sw_pressionado; ///< true se o botão SW estiver pressionado (LOW ativo).
} joystick_state_t;

/**
 * @brief Inicializa os pinos de GPIO e ADC para o joystick.
 * Deve ser chamada uma vez na inicialização do sistema.
 */
void joystick_init(void);

/**
 * @brief Lê o estado atual dos eixos X e Y do joystick e do seu botão.
 * @param state Ponteiro para uma estrutura joystick_state_t onde o estado será armazenado.
 */
void joystick_read(joystick_state_t *state);

#endif // JOYSTICK_H
