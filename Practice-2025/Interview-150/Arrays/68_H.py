# https://leetcode.com/problems/text-justification/description/?envType=study-plan-v2&envId=top-interview-150

def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        lines = []
        line = []

        while words:
            line_str = " ".join(line + words[:1])
            line_len = len(line_str)
            if line_len > maxWidth:
                if len(line) == 1:
                    lines.append(line[0].ljust(maxWidth))
                else:
                    words_width = sum(len(word) for word in line)
                    spaces = [1] * (len(line) - 1) + [0]
                    space_pos = 0
                    while (words_width + sum(spaces)) < maxWidth:
                        spaces[space_pos] += 1
                        space_pos = (space_pos + 1) % (len(line) - 1)
                    lines.append("".join(word + " " * space for word, space in zip(line, spaces)))
                line = []

            elif line_len == maxWidth:
                lines.append(line_str)
                line = []
                words.pop(0)
                
            else:
                line.append(words.pop(0))
        if line:
            lines.append(" ".join(line).ljust(maxWidth))
        return lines