from pathlib import Path
import subprocess
from PIL import Image, ImageDraw

out = Path("render-output")
out.mkdir(exist_ok=True)
preview = Path("docs/generated")
preview.mkdir(parents=True, exist_ok=True)
names = ["mandelbrot", "tri", "boat", "duck", "bell", "fish", "vase", "bird", "mask", "ship"]
subprocess.run(["gcc", "-O3", "Mandelbrot_python.c", "-o", "Mandelbrot_python.out", "-lm"], check=True)
gallery = Image.new("RGB", (5*256, 2*282), "#161b22")
draw = ImageDraw.Draw(gallery)
for i, name in enumerate(names):
    p = out / (name + ".png")
    subprocess.run(["./Mandelbrot_python.out", "0", "0", "0", str(p), str(i)], check=True)
    with Image.open(p) as im:
        assert im.size == (256, 256)
        x, y = i % 5 * 256, i // 5 * 282
        gallery.paste(im.convert("RGB"), (x, y))
        draw.text((x+8, y+261), f"{i}: {name}", fill="white")
gallery.save(preview / "gallery.webp", quality=87)
for zoom in (2, 4, 6, 8, 10):
    subprocess.run(["./Mandelbrot_python.out", str(zoom), "0.1068878173828125", "0.6374053955078125", str(out / f"zoom-{zoom}.png"), "0"], check=True)
