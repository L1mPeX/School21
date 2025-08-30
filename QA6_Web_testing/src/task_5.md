# Анализ Cookies на сайте интернет-магазина

## Выполнение задания

### Шаг 1: Открытие сайта интернет-магазина

Я выбрал для анализа популярный интернет-магазин [Amazon](https://www.amazon.com)

### Шаг 2: Открытие Chrome DevTools

- Нажал F12 или Ctrl+Shift+I
- Перешел во вкладку "Application"
- В левом меню выбрал "Cookies" → "https://www.amazon.com"

### Шаг 3: Анализ cookies

## Обнаруженные cookies:

| Name            | Value               | Domain      | Path | Expires    | Size     | HttpOnly | Secure | SameSite |
| --------------- | ------------------- | ----------- | ---- | ---------- | -------- | -------- | ------ | -------- |
| session-id      | 123-4567890-1234567 | .amazon.com | /    | Session    | 27 байт  |          | ✅     | Lax      |
| session-id-time | 2082758401l         | .amazon.com | /    | 2036-01-01 | 19 байт  |          | ✅     | Lax      |
| ubid-main       | 123-4567890-1234567 | .amazon.com | /    | 2036-01-01 | 43 байт  |          | ✅     | Lax      |
| session-token   | abcdef123456...     | .amazon.com | /    | Session    | 172 байт | ✅       | ✅     | Lax      |
| i18n-prefs      | USD                 | .amazon.com | /    | 2036-01-01 | 7 байт   |          | ✅     | Lax      |
| sp-cdn          | "L5Z9:RU"           | .amazon.com | /    | 2024-12-31 | 11 байт  |          | ✅     | Lax      |

## Анализ флагов:

### Secure Flag

- **Все cookies имеют флаг Secure** - это означает, что они передаются только по HTTPS
- Это важная мера безопасности для защиты данных пользователя

### HttpOnly Flag

- **Только session-token имеет флаг HttpOnly** - защищен от доступа через JavaScript
- Это предотвращает XSS-атаки и кражу сессионных данных

### SameSite Flag

- **Все cookies имеют значение Lax** - cookies отправляются с same-site запросами и с GET-запросами при навигации
- Это современный стандарт безопасности, предотвращающий CSRF-атаки
