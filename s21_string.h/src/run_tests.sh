#!/bin/bash

# Проверка наличия Docker
if ! command -v docker &> /dev/null; then
    echo "Ошибка: Docker не найден. Убедитесь что Docker установлен и добавлен в PATH" >&2
    echo "Можно установить Docker: https://docs.docker.com/get-docker/" >&2
    exit 1
fi

# Проверка существования Dockerfile
if [ ! -f "Dockerfile" ]; then
    echo "Ошибка: Dockerfile не найден в корне проекта" >&2
    exit 1
fi

# Удаляем старый образ (игнорируем ошибки если его нет)
echo "Очистка старого образа..."
docker rmi -f string-tests &> /dev/null

# Собираем новый образ
echo "Сборка Docker образа..."
docker build -t string-tests .

if [ $? -ne 0 ]; then
    echo "Ошибка при сборке Docker образа" >&2
    exit 1
fi

# Запускаем тесты
echo "Запуск тестов..."
docker run --rm \
    -v $(pwd)/report:/app/report \
    string-tests

TEST_RESULT=$?
if [ $TEST_RESULT -ne 0 ]; then
    echo "Тесты завершились с ошибкой (код $TEST_RESULT)" >&2
    exit $TEST_RESULT
fi

echo ""
echo "Все тесты успешно пройдены!"
exit 0