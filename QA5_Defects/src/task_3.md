# Self-XSS через модификацию Object.prototype

**Критичность:** Medium  
**Приоритет:** Medium  
**Тип:** Уязвимость безопасности  
**Окружение:** Все современные браузеры (Chrome, Firefox, Safari)  
**Задействованные URL:** Весь скоуп

## Описание

Модификация Object.prototype позволяет сделать DOM XSS инъекцию через консоль, позволяющую исполнять недостоверный JavaScript код с доступом ко всем оъектам

## Шаги для воспроизведения

1. Открыть консоль в браузере (F12 → Inspect → Console)
2. Исполните следующее:

```javascript
Object.prototype.theme = "<img src=x onerror=alert(document.domain)>";
document.body.innerHTML = {}.theme;
```

## Ожидаемый результат

- Требования CSP не позволят создать img объект

## Имеющийся результат

- Вреденосный код позволяет вызвать XSS в обход CSP

## Proof of Concept

```javascript
Object.prototype.theme = "<img src=x onerror=alert(document.domain)>";
document.body.innerHTML = {}.theme;
```

## Потенциальный ущерб

- Потенциальный session hijacking
- Open redirect

## Рекомендуемые действия для исправления

1. Поставить строгий CSP заголовок:

```http
Content-Security-Policy: default-src 'self'; object-src 'none'
```

2. Отключить прототипы:

```javascript
Object.freeze(Object.prototype);
```
