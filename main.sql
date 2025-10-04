WITH ordered_transactions AS (
    SELECT
        c.iban1, c.iban2, c.iban3, c.iban4, c.iban5, c.iban6, c.iban7, c.iban8,
        t.dt,
        t.amount,
        ROW_NUMBER() OVER (PARTITION BY c.id ORDER BY t.dt ASC) AS rn
    FROM
        customers c
    JOIN
        transactions t ON c.id = t.customer_id
)
SELECT
    CONCAT(
        iban1, ' ', iban2, ' ', iban3, ' ', iban4, ' ', iban5, ' ', iban6, ' ', iban7, ' ', iban8, ' ',
        GROUP_CONCAT(
            CASE
                WHEN rn = 1 THEN CAST(amount AS CHAR)
                WHEN amount >= 0 THEN CONCAT(' +', CAST(amount AS CHAR))
                ELSE CONCAT(' ', CAST(amount AS CHAR))
            END
            ORDER BY dt SEPARATOR ' '
        )
    )
FROM ordered_transactions
GROUP BY
    iban1, iban2, iban3, iban4, iban5, iban6, iban7, iban8
ORDER BY
    SUM(amount) DESC;