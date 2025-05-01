mkdir -p build/clay                                                       \
&& clang                                                                  \
-Wall                                                                     \
-Werror                                                                   \
-Os                                                                       \
-DCLAY_WASM                                                               \
-mbulk-memory                                                             \
--target=wasm32                                                           \
-nostdlib                                                                 \
-Wl,--strip-all                                                           \
-Wl,--export-dynamic                                                      \
-Wl,--no-entry                                                            \
-Wl,--export=__heap_base                                                  \
-Wl,--export=ACTIVE_RENDERER_INDEX                                        \
-Wl,--initial-memory=6553600                                              \
-o build/clay/index.wasm                                                  \
main.c                                                                    \
-v
&& cp index.html build/clay/index.html && cp -r images/ build/clay/images
