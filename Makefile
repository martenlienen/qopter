messages: messages-fw messages-gcs

messages-fw:
  mavgen.py --lang C                            \
            --wire-protocol 1.0                 \
            -o fw/src/mavlink                   \
            --no-validate                       \
            messages.xml

messages-gcs:
  mavgen.py --lang Python                       \
            --wire-protocol 1.0                 \
            -o gcs/mavlink.py                   \
            --no-validate                       \
            messages.xml
