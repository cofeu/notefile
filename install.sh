#!/bin/sh

set -e

APP_NAME="notefile"
INSTALL_DIR="$HOME/.local/bin"

echo "=== NoteFile Installer ==="
echo

# Gerekli araçları kontrol et
if command -v clang >/dev/null 2>&1; then
    CC="clang"
elif command -v gcc >/dev/null 2>&1; then
    CC="gcc"
else
    echo "HATA: clang veya gcc bulunamadı."
    echo "Lütfen bir C derleyicisi yükleyin."
    exit 1
fi

if ! command -v make >/dev/null 2>&1; then
    echo "HATA: make bulunamadı."
    echo "Lütfen make paketini yükleyin."
    exit 1
fi

echo "Derleyici: $CC"
echo "Make: bulundu"
echo

# Proje dizinini bul
SCRIPT_DIR="$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)"
cd "$SCRIPT_DIR"

echo "[1/3] NoteFile derleniyor..."

make CC="$CC"

if [ ! -f "$APP_NAME" ]; then
    echo "HATA: Derleme tamamlandı fakat $APP_NAME oluşturulmadı."
    exit 1
fi

echo "Derleme başarılı."
echo

# Kurulum dizinini oluştur
echo "[2/3] Kurulum dizini hazırlanıyor..."

mkdir -p "$INSTALL_DIR"

# Binary'yi kur
cp "$APP_NAME" "$INSTALL_DIR/$APP_NAME"
chmod +x "$INSTALL_DIR/$APP_NAME"

echo "Kuruldu: $INSTALL_DIR/$APP_NAME"
echo

# PATH kontrolü
echo "[3/3] PATH kontrol ediliyor..."

case ":$PATH:" in
    *":$INSTALL_DIR:"*)
        echo "\$PATH zaten doğru."
        ;;
    *)
        echo "\$PATH içerisinde $INSTALL_DIR bulunamadı."

        SHELL_NAME="$(basename "${SHELL:-sh}")"

        case "$SHELL_NAME" in
            bash)
                SHELL_RC="$HOME/.bashrc"
                ;;
            zsh)
                SHELL_RC="$HOME/.zshrc"
                ;;
            *)
                SHELL_RC=""
                ;;
        esac

        if [ -n "$SHELL_RC" ]; then
            if ! grep -Fq "$INSTALL_DIR" "$SHELL_RC" 2>/dev/null; then
                printf '\n# NoteFile\nexport PATH="$HOME/.local/bin:$PATH"\n' >> "$SHELL_RC"
                echo "PATH $SHELL_RC içerisine eklendi."
            else
                echo "PATH kaydı zaten mevcut."
            fi
        else
            echo "Shell otomatik olarak tanınamadı."
            echo "Şunu shell ayarlarınıza ekleyin:"
            echo 'export PATH="$HOME/.local/bin:$PATH"'
        fi
        ;;
esac

echo
echo "=== Kurulum tamamlandı ==="
echo
echo "NoteFile:"
echo "  $INSTALL_DIR/$APP_NAME"
echo

case ":$PATH:" in
    *":$INSTALL_DIR:"*)
        echo "Artık şunu çalıştırabilirsiniz:"
        echo "  notefile"
        ;;
    *)
        echo "Yeni PATH'in aktif olması için terminali yeniden açın"
        echo "veya shell ayarınızı yeniden yükleyin."
        ;;
esac