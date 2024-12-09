#include <stdio.h>
#include <string.h>
#include <limits.h>

int main()
{
	char line[256];
	printf("Введіть рядок (максимум 255 символів, закінчується крапкою): ");
	if (fgets(line, sizeof(line), stdin) == NULL)
	{
		printf("Помилка введення.\n");
		return 1;
	}

	line[strcspn(line, "\n")] = '\0';

	int len = strlen(line);
	if (len == 0 || line[len - 1] != '.')
	{
		printf("Рядок повинен закінчуватись крапкою.\n");
		return 1;
	}

	int minLength = INT_MAX;
	int currentLength = 0;

	for (int i = 0; i < len; i++)
	{
		if (line[i] == ' ' || line[i] == '.')
		{
			if (currentLength > 0)
			{
				if (currentLength < minLength)
				{
					minLength = currentLength;
				}
				currentLength = 0;
			}
		}
		else
		{
			currentLength++;
		}
	}

	if (minLength == INT_MAX)
	{
		printf("Слова у рядку не знайдено.\n");
	}
	else
	{
		printf("Довжина найкоротшого слова: %d\n", minLength);
	}

	return 0;
}
