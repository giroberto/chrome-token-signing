/*
 * Chrome Token Signing Native Host
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "Labels.h"

#include <map>
#include <vector>

using namespace std;

Labels Labels::l10n = Labels();

Labels::Labels() {
    setLanguage("pt_BR");
}

void Labels::setLanguage(const string &language) {
    static std::map<std::string, int> languages = {{"et",0}, {"en",1}, {"ru",2}, {"est",0}, {"eng",1}, {"rus",2}, {"pt_BR",3}};
    auto pos = languages.find(language);
    selectedLanguage = pos == languages.end() ? 1 : pos->second;
}

string Labels::get(const string &labelKey) const {
    static std::map<std::string,std::vector<std::string> > labels = {
        {"enter PIN2",{
            "Allkirjastamiseks sisesta PIN2:",
            "For signing enter PIN2:",
            "Для подписания введите PIN2:",
            "Para assinar insira o PIN2:"
        }},
        {"enter PIN2 pinpad", {
            "Allkirjastamiseks sisesta PIN2 kaardilugeja sõrmistikult",
            "For signing enter PIN2 from PIN pad",
            "Для подписания введите PIN2 с PIN-клавиатуры",
            "Para assinar insira o PIN2 no teclado",
        }},
        {"tries left",{"Katseid jäänud:", "Tries left:", "Возможных попыток:", "Tentativas restantes: "}},
        {"incorrect PIN2",{"Vale PIN2! ", "Incorrect PIN2! ", "Неправильный PIN2! ", "PIN2 incorreto! "}},
        {"signing",{"Allkirjastamine", "Signing", "Подписание", "Assinando"}},
        {"PIN2 blocked",{
            "PIN2 blokeeritud, ei saa allkirjastada!",
            "PIN2 blocked, cannot sign!",
            "PIN2 блокирован, невозможно подписать!",
            "PIN2 Bloqueado, impossível assinar"
        }},
        {"error", {"Viga", "Error", "Ошибка", "Erro"}},
        {"cancel", {"Katkesta", "Cancel", "Отменить", "Cancelar"}},
        {"sign", {"Allkirjasta", "Sign", "Подписать", "Assinar"}},

        {"select certificate", {"Sertifikaadi valik", "Select certificate", "Выбор сертификата", "Selecionar Certificado"}},
        {"select", {"Vali", "Select", "Выбрать", "Selecione"}},
        {"certificate", {"Sertifikaat", "Certificate", "Сертификат", "Certificado"}},
        {"type", {"Tüüp", "Type", "Тип", "Tipo"}},
        {"valid to", {"Kehtiv kuni" ,"Valid to", "Действительный до", "Válido até"}},
        {"cert info", {
            "Sertifikaadi valikuga nõustun oma nime ja isikukoodi edastamisega teenusepakkujale.",
            "By selecting a certificate I accept that my name and personal ID code will be sent to service provider.",
            "Выбирая сертификат, я соглащаюсь с тем, что мое имя и личный код будут переданы представителю услуг.",
            "Ao selecionar o certificado eu aceito que meu nome e código pessoal será enviado ao serviço"
        }}
    };
    return labels.at(labelKey)[selectedLanguage];
}
