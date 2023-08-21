-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Pull up crime scene report for date and location of crime
SELECT description FROM crime_scene_reports WHERE street = 'Humphrey Street'
AND month = 7 AND day = 28 AND year = 2021;

-- Get interviews of the 3 witnesses
SELECT transcript FROM interviews WHERE month = 7 AND day = 28 AND year = 2021;

-- Check ATM withdrawal and get bank account number to get list of person ids (people.id)
SELECT person_id FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street'
AND month = 7 AND day = 28 AND year = 2021 AND transaction_type = 'withdraw');

-- Get license plate from bakery security log (people.license_plate)
SELECT license_plate FROM bakery_security_logs WHERE month = 7
AND day = 28 AND year = 2021 AND activity = 'exit' AND hour = 10
AND minute > 15 AND minute < 25;

--Get destination of first flight out of Fiftyville on 7/29/21    (ANSWER: NEW YORK CITY)
SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE origin_airport_id =
(SELECT id FROM airports WHERE city = 'Fiftyville')
AND month = 7 AND day = 29 AND year = 2021 ORDER BY hour LIMIT 1);

--Get flight id of first flight out of Fiftyville on 7/29/21
SELECT id FROM flights WHERE origin_airport_id =
(SELECT id FROM airports WHERE city = 'Fiftyville')
AND month = 7 AND day = 29 AND year = 2021 ORDER BY hour LIMIT 1;

--Get list of passport numbers from flight (people.passport_number)
SELECT passport_number FROM passengers WHERE flight_id =
(SELECT id FROM flights WHERE origin_airport_id =
(SELECT id FROM airports WHERE city = 'Fiftyville')
AND month = 7 AND day = 29 AND year = 2021 ORDER BY hour LIMIT 1);

--Get name and phone number of thief (Luca: (389)555-5198, Bruce: (367)555-5533)
SELECT name, phone_number FROM people
WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street'
AND month = 7 AND day = 28 AND year = 2021 AND transaction_type = 'withdraw'))
AND passport_number IN
(SELECT passport_number FROM passengers WHERE flight_id =
(SELECT id FROM flights WHERE origin_airport_id =
(SELECT id FROM airports WHERE city = 'Fiftyville')
AND month = 7 AND day = 29 AND year = 2021 ORDER BY hour LIMIT 1))
AND license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE month = 7
AND day = 28 AND year = 2021 AND activity = 'exit' AND hour = 10
AND minute > 15 AND minute < 25);

--See phone call log when theft occurred (ANSWER: thief is BRUCE)
SELECT caller, receiver, FROM phone_calls
WHERE month = 7 AND day = 28 AND year = 2021
AND duration < 60 ORDER BY duration;

--Get name of accomplice (375) 555-8161 (ANSWER: accomplice is ROBIN)
SELECT name FROM people WHERE phone_number = '(375) 555-8161';
