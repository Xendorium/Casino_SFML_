# Casino_SFML_

Nazwa - Casino(SFML)

Projekt Casino(SFML) jest czymś ala symulatorem kasyna. 
Postanowiłem stworzyc go (jako projekt zaliczeniowy na obiektówke) ze względu na fakt, że idea kasyna sama w sobie oraz czynnik losowości jaka się za nim kryje od zawsze mnie interesowała, 
a ponadto wiedziałem ,że podczas pisanai go będe się dobrze bawił.

Aplikacja w głónej mierze skłąda się z menu oraz wyboru jednej z dwóch(na razie dwie, w planach jest jeszcze dodanie ruletki) gier: Blackjack orax Slots.
Gra Blackjack jest grą karcianą, z zasadami zgodnymi z tymi obowiązującymi w prawdziwych kasynach. 
Sloty natomiast to typowa maszyna, która losuje po 3 elementy z danej puli. Gracz wygrywa jeżeli wszystkie z elementy będą jednakowe.
Wszystko zrobione jest w interfejsie graficznym SFML.

Aby zainstalować Casyno należy pobrać je z poniższego linku: 
https://drive.google.com/file/d/1t9o_XzNMScQ1i8CsI3Q7cxuvP-WXIIf5/view?usp=sharing
Następnie wypakować i odpalić plik wykonywalny exe. 
Po uruchomieniu wyskoczy nam menu, które po wciśnięciu przysicku start przekieruje nas do menu wyboru gry.
Następnie cieszyć się już można działającą aplikacją.

Konfiguracja SFML: pobrany folder SFML - GCC 7.3.0 MinGW (SEH) - 64-bit oraz MnGW - MinGW Builds 7.3.0 (64-bit) po rozpakowaniu przerzuciłem do dysku C:/
Nastepnie Toolchainsy skonfigurowałem pod pobraną wersję MinGW. DO folder cmake_modules wrzuciłem FindSFML.
