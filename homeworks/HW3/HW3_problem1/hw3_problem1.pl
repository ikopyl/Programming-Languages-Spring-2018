% Family relationships

m([
    'Prince Andrew of Greece and Denmark',
    'King George VI',
    'Prince Philip',
    'Antony Armstrong-Jones',
    'Prince Charles',
    'Mark Philips',
    'Prince Andrew',
    'David Armstrong-Jones',
    'Prince Edward',
    'Peter Philips',
    'Jasper Cable-Alexander',
    'Prince William',
    'Prince Harry',
    'James, Viscount Severn'
]).

f([
    'Princess Alice of Battenberg',
    'Elizabeth the Queen Mother',
    'Queen Elizabeth II',
    'Princess Margaret',
    'Someone else',
    'Princess Diana',
    'Princess Anne',
    'Polly Higson',
    'Sarah Margaret Ferguson',
    'Sophie Helen Rhys-Jones',
    'Lady Sarah Chatto',
    'Zara Tindall',
    'Lady Frances von Hofmannsthal',
    'Princess Beatrice',
    'Princess Eugenie',
    'Lady Louise Windsor'
]).

family([
    'Prince Andrew of Greece and Denmark',
    'Princess Alice of Battenberg',
    [
        'Prince Philip'
    ]
]).

family([
    'King George VI',
    'Elizabeth the Queen Mother',
    [
        'Queen Elizabeth II',
        'Princess Margaret'
    ]
]).

family([
    'Prince Philip',
    'Queen Elizabeth II',
    [
        'Prince Charles',
        'Princess Anne',
        'Prince Andrew',
        'Prince Edward'
    ] 
]).

family([
    'Antony Armstrong-Jones',
    'Princess Margaret',
    [
        'David Armstrong-Jones',
        'Lady Sarah Chatto'
    ]
]).

family([
    'Antony Armstrong-Jones',
    'Someone else',
    [
        'Polly Higson',
        'Jasper Cable-Alexander',
        'Lady Frances von Hofmannsthal'
    ]
]).

family([
    'Prince Charles',
    'Princess Diana',
    [
        'Prince William',
        'Prince Harry'
    ]
]).

family([
    'Mark Philips',
    'Princess Anne',
    [
        'Peter Philips',
        'Zara Tindall'
    ]
]).


family([]).
family([]).
family([]).


